using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

namespace Waage
{
    class SerialPortClass
    {
        SerialPort serialPort;
        MainWindow main;
        List<byte> rxData = new List<byte>();

        public SerialPortClass(MainWindow main)
        {
            this.main = main;
            serialPort = new SerialPort();
            AddListener();
            InitComPort();
        }


        public void SendData(char[] data)
        {
            if (serialPort.IsOpen)
            {
                serialPort.Write(data, 0, data.Length);
            }
            
        }

        public void SendData(string data)
        {
            SendData(data.ToCharArray());
        }


        private void InitComPort()
        {
            main.cbCOM.Items.Clear();
                string[] sPortName = SerialPort.GetPortNames();
                foreach(string s in sPortName)
                {
                    main.cbCOM.Items.Add(s);
                }
        }



        private void AddListener()
        {
            main.cmdConnect.Click += CmdConnect_Click;
            main.cmdDisconnect.Click += CmdDisconnect_Click;
            main.cmdRefresh.Click += CmdRefresh_Click;
        }

        private void CmdRefresh_Click(object sender, RoutedEventArgs e)
        {
            InitComPort();
        }

        private void CmdDisconnect_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (serialPort.IsOpen)
            {
                try
                {
                    serialPort.Close();
                    main.lblStatus.Content = "Disconnected";
                }
                catch(Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }

            }
        }

        private void CmdConnect_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (serialPort.IsOpen)
            {
                MessageBox.Show("Serialport already open", "SerialPort", MessageBoxButton.OK, MessageBoxImage.Information);
                return;
            }

            if (main.cbCOM.SelectedIndex == -1)
            {
                MessageBox.Show("No COM Port selected", "SerialPort", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            try
            {
                serialPort.BaudRate = 38400;
                serialPort.Parity = Parity.None;
                serialPort.StopBits = StopBits.One;
                serialPort.PortName = main.cbCOM.SelectedItem.ToString();
                serialPort.DataBits = 8;
                serialPort.Handshake = Handshake.None;
                serialPort.RtsEnable = true;
                serialPort.ReadTimeout = 100;
                serialPort.WriteTimeout = 100;
                serialPort.DataReceived += SerialPort_DataReceived;
                serialPort.Open();
                main.lblStatus.Content = main.cbCOM.SelectedItem.ToString() + " Connected";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            int counter = 0;
            byte[] buffer = new byte[16];
            
            try
            {
                for (int i = 0; i < 16; i++)
                {
                    buffer[i] = (byte)serialPort.ReadByte();
                    counter++;
                }
            }
            catch { }

            rxData.Clear();
            for(int i = 0; i< counter; i++)
            {
                rxData.Add(buffer[i]);
            }
            IsDataReady = true;
        }

        
        public List<byte> getData()
        {
            return rxData;
        }

        private bool isDataReady;
        public bool IsDataReady {
            get
            {
                if (isDataReady)
                {
                    isDataReady = false;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            set
            {
                isDataReady = value;
            }
        }




    }
}
