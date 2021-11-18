using Microsoft.Office.Interop.Excel;
using Microsoft.Win32;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

namespace Waage
{
    internal class Control
    {
        private readonly MainWindow main;
        private readonly SerialPortClass sPort;
        private readonly List<LogBookEntry> logBookEntries = new List<LogBookEntry>();
        private Microsoft.Office.Interop.Excel.Application excelApplication;
        private _Workbook excelWorkbook;
        private _Worksheet excelWorksheet;

        private int counter = 0;

        public Control(MainWindow main, SerialPortClass sPort)
        {
            this.sPort = sPort;
            this.main = main;
            AddListener();
        }

        /// <summary>
        /// Add eventlistener
        /// </summary>
        private void AddListener()
        {
            main.cmdClearEntries.Click += CmdClearEntries_Click;
            main.cmdClearLog.Click += CmdClearLog_Click;
            main.cmdExport.Click += CmdExport_Click;
            main.cmdReadLog.Click += CmdReadLog_Click;
        }

        private void CmdReadLog_Click(object sender, RoutedEventArgs e)
        {
            if (!sPort.IsConnected)
            {
                _ = MessageBox.Show("Kein Gerät verbunden", "Device Error", MessageBoxButton.OK, MessageBoxImage.Error); ;
                return;
            }

            //reset progressbar
            main.pbProgress.Value = 0;
            //clear listview items
            main.listView.Items.Clear();

            //read logbooksize
            sPort.SendData("100000");
            if (!Wait4Data(3))
            {
                return;
            }
            List<byte> data = sPort.GetData();
            int logBookSize = (data[0] * 100) + (data[1] * 10) + data[2];

            //set progressbar max value to logbooksize - 1
            main.pbProgress.Maximum = logBookSize - 1;

            Task DataRead = new Task(() => Read(logBookSize));
            DataRead.Start();

            data.Clear();
        }

        /// <summary>
        /// 
        /// </summary>
        private void Read(int logBookSize)
        {
            int addr = 100001;
            for (int i = 0; i < logBookSize - 1; i++)
            {
                addr = 100001 + i;
                sPort.SendData(addr.ToString());

                if (!Wait4Data(3))
                {
                    return;
                }
                List<byte> entrie = sPort.GetData();

                LogBookEntry logBookEntry = new LogBookEntry(entrie[0], entrie[1], entrie[2], entrie[3], entrie[4], entrie[5], entrie[7], entrie[8], entrie[10], entrie[11], entrie[12], entrie[14]);
                logBookEntries.Add(logBookEntry);

                System.Windows.Application.Current.Dispatcher.Invoke(new System.Action(() =>
                {
                    _ = main.listView.Items.Add(logBookEntry);
                    main.pbProgress.Value = counter;
                }));



                entrie.Clear();
                counter++;
            }

            System.Windows.Application.Current.Dispatcher.Invoke(new System.Action(() =>
            {
                main.pbProgress.Value = counter;
            }));
        }


        private bool Wait4Data(int timeOut_s)
        {
            int timeOut = 0;
            while (!sPort.IsDataReady)
            {
                if (timeOut > timeOut_s)
                {
                    _ = MessageBox.Show("Zeitüberschreitung der Anforderung", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                    return false;
                }
                Thread.Sleep(1000);
                timeOut++;
            }
            return true;
        }


        private void CmdExport_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            counter = 0;
            main.pbProgress.Maximum = logBookEntries.Count;

            Task writeData = new Task(() => Write());
            writeData.Start();
        }


        private void Write()
        {
            counter++;
            excelApplication = new Microsoft.Office.Interop.Excel.Application();
            counter++;
            excelWorkbook = excelApplication.Workbooks.Add(Missing.Value);
            counter++;
            excelWorksheet = (Worksheet)excelWorkbook.Sheets.Add();
            counter++;
            excelWorksheet.Cells[1, 1] = "Datum";
            excelWorksheet.Cells[1, 2] = "Zeit";
            excelWorksheet.Cells[1, 3] = "Gewicht";
            excelWorksheet.Cells[1, 4] = "Preis";
            excelWorksheet.Cells[1, 5] = "Wachstyp";
            counter++;
            int entrieSize = logBookEntries.Count;

            for (int i = 0; i < entrieSize; i++)
            {
                excelWorksheet.Cells[i + 2, 1] = logBookEntries[i].Datum;
                excelWorksheet.Cells[i + 2, 2] = logBookEntries[i].Zeit;
                excelWorksheet.Cells[i + 2, 3] = logBookEntries[i].Gewicht;
                excelWorksheet.Cells[i + 2, 4] = logBookEntries[i].Preis;
                excelWorksheet.Cells[i + 2, 5] = logBookEntries[i].Wachstyp.ToString();
                counter++;
            }


            string fileName;
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            _ = saveFileDialog.ShowDialog();
            if (saveFileDialog.SafeFileName != "")
            {
                fileName = saveFileDialog.SafeFileName;
                excelApplication.ActiveWorkbook.SaveAs(Path.GetFullPath(fileName) + ".xlsx");
            }


            excelWorkbook.Close(0);
            excelApplication.Quit();
        }


        private void CmdClearLog_Click(object sender, RoutedEventArgs e)
        {
            if (MessageBox.Show("Wollen Sie das Logbuch Löschen?", "Logbuch löschen", MessageBoxButton.YesNo, MessageBoxImage.Question) == MessageBoxResult.Yes)
            {
                main.listView.Items.Clear();
                sPort.SendData("F00000");
            }
        }

        private void CmdClearEntries_Click(object sender, RoutedEventArgs e)
        {
            main.listView.Items.Clear();
        }
    }
}
