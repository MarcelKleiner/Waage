using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Windows;

namespace Waage
{
    internal class SerialPortClass
    {
        private readonly SerialPort serialPort;
        private readonly MainWindow main;
        private readonly List<byte> rxData = new List<byte>();

        public SerialPortClass(MainWindow main)
        {
            this.main = main;
            serialPort = new SerialPort();
            AddListener();
            InitComPort();
        }

        /// <summary>
        /// Add event listener
        /// </summary>
        private void AddListener()
        {
            main.cmdConnect.Click += CmdConnect_Click;
            main.cmdDisconnect.Click += CmdDisconnect_Click;
            main.cmdRefresh.Click += CmdRefresh_Click;
        }




        /// <summary>
        /// send data over serial port
        /// </summary>
        /// <param name="data">data as string</param>
        public void SendData(string data)
        {
            SendData(data.ToCharArray());
        }



        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void CmdRefresh_Click(object sender, RoutedEventArgs e)
        {
            InitComPort();
        }

        private void CmdDisconnect_Click(object sender, RoutedEventArgs e)
        {
            if (serialPort.IsOpen)
            {
                try
                {
                    serialPort.Close();
                    main.lblStatus.Content = "Disconnected";
                }
                catch (Exception ex)
                {
                    _ = MessageBox.Show(ex.Message);
                }

            }
        }

        private void CmdConnect_Click(object sender, RoutedEventArgs e)
        {
            if (serialPort.IsOpen)
            {
                _ = MessageBox.Show("Serialport already open", "SerialPort", MessageBoxButton.OK, MessageBoxImage.Information);
                return;
            }

            if (main.cbCOM.SelectedIndex == -1)
            {
                _ = MessageBox.Show("No COM Port selected", "SerialPort", MessageBoxButton.OK, MessageBoxImage.Error);
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
                _ = MessageBox.Show(ex.Message);
                return;
            }
        }

        /// <summary>
        /// send data over serial port
        /// </summary>
        /// <param name="data">data as char arry</param>
        public void SendData(char[] data)
        {
            if (serialPort.IsOpen)
            {
                serialPort.Write(data, 0, data.Length);
            }
        }

        /// <summary>
        /// serial port data receive interrupt
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
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
            for (int i = 0; i < counter; i++)
            {
                rxData.Add(buffer[i]);
            }
            IsDataReady = true;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public List<byte> GetData()
        {
            return rxData;
        }


        private bool isDataReady;
        public bool IsDataReady
        {
            get
            {
                if (isDataReady)
                {
                    isDataReady = false;
                    return true;
                }
                return false;
            }
            set => isDataReady = value;
        }

        public bool IsConnected => serialPort.IsOpen;



        /// <summary>
        /// Read all avaliable comports 
        /// </summary>
        private void InitComPort()
        {
            main.cbCOM.Items.Clear();
            foreach (string s in SerialPort.GetPortNames())
            {
                _ = main.cbCOM.Items.Add(s);
            }
        }

    }
}
