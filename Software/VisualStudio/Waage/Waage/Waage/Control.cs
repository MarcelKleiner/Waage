using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using Microsoft.Office.Interop.Excel;
using Microsoft.Win32;

namespace Waage
{
    class Control
    {
        MainWindow main;
        SerialPortClass sPort;
        List<LogBookEntry> logBookEntries = new List<LogBookEntry>();
        DataGridRow row;
        int logBookSize;

        Microsoft.Office.Interop.Excel.Application excelApplication;
        _Workbook excelWorkbook;
        _Worksheet excelWorksheet;


        Thread progressBarThread;
        bool isActive;
        int counter = 0;

        Thread readData;
        Thread writeData;



        public Control(MainWindow main, SerialPortClass sPort)
        {
            this.sPort = sPort;
            this.main = main;

            AddListener();
        }

        private void AddListener()
        {
            main.cmdClearEntries.Click += CmdClearEntries_Click;
            main.cmdClearLog.Click += CmdClearLog_Click;
            main.cmdExport.Click += CmdExport_Click;
            main.cmdReadLog.Click += CmdReadLog_Click;
        }

        private void CmdReadLog_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            main.pbProgress.Value = 0;
            main.listView.Items.Clear();
            sPort.SendData("100000");
            while (!sPort.IsDataReady) ;
            List<byte> data = sPort.getData();
            logBookSize = 0;
            logBookSize = logBookSize + data[0] * 100;
            logBookSize = logBookSize + data[1] * 10;
            logBookSize = logBookSize + data[2];
            main.pbProgress.Maximum = logBookSize - 1;


            isActive = true;
            progressBarThread = new Thread(new ThreadStart(pbThread));
            progressBarThread.Start();
            counter = 0;

            readData = new Thread(new ThreadStart(read));
            readData.Start();

            data.Clear();

        }

        void read()
        {

            Int32 addr = 100001;
            for (Int32 i = 0; i < logBookSize - 1; i++)
            {
                addr = 100001 + i;
                sPort.SendData(addr.ToString());
                while (!sPort.IsDataReady) ;
                List<byte> entrie = sPort.getData();

                LogBookEntry logBookEntry = new LogBookEntry(entrie[0], entrie[1], entrie[2], entrie[3], entrie[4], entrie[5], entrie[7], entrie[8], entrie[10], entrie[11], entrie[12], entrie[14]);
                logBookEntries.Add(logBookEntry);

                System.Windows.Application.Current.Dispatcher.Invoke(new System.Action(() =>
                {
                    main.listView.Items.Add(logBookEntry);
                }));



                entrie.Clear();
                counter++;

            }

            isActive = false;
        }

        void pbThread()
        {
            while (isActive)
            {
                System.Windows.Application.Current.Dispatcher.Invoke(new System.Action(() =>
                {
                    main.pbProgress.Value = this.counter;
                }));
                Thread.Sleep(1);
            }
            System.Windows.Application.Current.Dispatcher.Invoke(new System.Action(() =>
            {
                main.pbProgress.Value = main.pbProgress.Maximum;
            }));
        }

        private void CmdExport_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            this.counter = 0;
            isActive = true;
            progressBarThread = new Thread(new ThreadStart(pbThread));
            progressBarThread.Start();
            main.pbProgress.Maximum = logBookEntries.Count;

            writeData = new Thread(new ThreadStart(write));
            writeData.Start();
        }


        private void write()
        {
            this.counter++;
            excelApplication = new Microsoft.Office.Interop.Excel.Application();
            this.counter++;
            excelWorkbook = excelApplication.Workbooks.Add(Missing.Value);
            this.counter++;
            excelWorksheet = (Worksheet)excelWorkbook.Sheets.Add();
            this.counter++;
            excelWorksheet.Cells[1, 1] = "Datum";
            excelWorksheet.Cells[1, 2] = "Zeit";
            excelWorksheet.Cells[1, 3] = "Gewicht";
            excelWorksheet.Cells[1, 4] = "Preis";
            excelWorksheet.Cells[1, 5] = "Wachstyp";
            this.counter++;
            int entrieSize = logBookEntries.Count;

            for (int i = 0; i < entrieSize; i++)
            {
                excelWorksheet.Cells[ i + 2,1] = logBookEntries[i].datum;
                excelWorksheet.Cells[ i + 2, 2] = logBookEntries[i].zeit;
                excelWorksheet.Cells[ i + 2, 3] = logBookEntries[i].gewicht;
                excelWorksheet.Cells[ i + 2, 4] = logBookEntries[i].preis;
                excelWorksheet.Cells[ i + 2, 5] = logBookEntries[i].wachstyp.ToString();
                this.counter++;
            }

            isActive = false;
            string fileName;
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.ShowDialog();
            if (saveFileDialog.SafeFileName != "")
            {
                fileName = saveFileDialog.SafeFileName;
                excelApplication.ActiveWorkbook.SaveAs(Path.GetFullPath(fileName) + ".xlsx");
            }


            excelWorkbook.Close(0);
            excelApplication.Quit();
        }


        private void CmdClearLog_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (MessageBox.Show("Wollen Sie das Logbuch Löschen?", "Logbuch löschen", MessageBoxButton.YesNo, MessageBoxImage.Question) == MessageBoxResult.Yes)
            {
                main.listView.Items.Clear();
                sPort.SendData("F00000");
            }

        }

        private void CmdClearEntries_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            main.listView.Items.Clear();
        }
    }
}
