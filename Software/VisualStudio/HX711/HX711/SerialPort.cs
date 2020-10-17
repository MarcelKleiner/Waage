using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

namespace HX711
{


    class SerialPortClass
    {
        SerialPort serialPort;
        Thread rxThread;
        MainWindow main;
        public SerialPortClass(MainWindow main)
        {
            this.main = main;
            main.cmdCon.Click += CmdCon_Click1;
            // rxThread = new Thread(new ThreadStart(RXData));
            serialPort = new SerialPort();
        }

        private void CmdCon_Click1(object sender, System.Windows.RoutedEventArgs e)
        {
            try
            {
                serialPort.BaudRate = 38400;
                serialPort.Parity = Parity.None;
                serialPort.StopBits = StopBits.One;
                serialPort.PortName = "COM11";
                serialPort.DataBits = 8;
                serialPort.Handshake = Handshake.None;
                serialPort.RtsEnable = true;
                serialPort.DataReceived += SerialPort_DataReceived1;
                serialPort.Open();


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        private void SerialPort_DataReceived1(object sender, SerialDataReceivedEventArgs e)
        {
            int rawData = 0;
            int counter = 0;
            byte[] buffer = new byte[10];
            char data;
            while ((data = (char)serialPort.ReadByte()) != 0)
            {
                buffer[counter] = (byte)data;
                counter++;
            }
            counter = 0;

            rawData = ((int)buffer[2]) << 8;
            rawData = rawData + ((int)buffer[1]);
            //rawData = rawData + ((int)buffer[0]);
            //rawData = rawData << 8 + (int)buffer[1];
            //rawData = rawData << 16 + (int)buffer[2];

            Application.Current.Dispatcher.BeginInvoke(new Action(() =>
                main.txtRaw.Text = rawData.ToString()

            ));

            double weight = 0;
            if (rawData < 1010)
            {
                weight = 0.01;
            }
            else
            {
                weight = (((double)rawData - 1010) * 0.29755434);
            }
            Application.Current.Dispatcher.BeginInvoke(new Action(() =>
            main.txtWeight.Text = weight.ToString("0.#")
             ));
        }

        private void SerialPort_DataReceived()
        {


        }





    }




}
