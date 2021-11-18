using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Waage
{
    class LogBookEntry
    {
        private DateTime _dateTime;
        private double _gewicht;
        private double _preis;

        public enum WAX_TYPE
        {
            BIENENWACHS = 1,
            PARAFINWACHS,
            SUMME
        }

        public LogBookEntry(byte Y, byte M, byte D, byte h, byte m, byte s, byte w1, byte w2, byte p1, byte p2, byte p3, byte WT)
        {
            SetDateTime(Y, M, D, h, m, s);


            short weight =   (short)((w1 << 8) + w2);
            SetGewicht((double)weight / 1000);

            int prize = ((p1 << 16) + (p2 << 8) + p3);
            if ((p1 & 0x80) == 0x80)
            {
                SetPreis((double)((0xFFFFFF - prize) * -1) / 100);
            }
            else
            {
                SetPreis((double)prize/100);
            }

            Wachstyp = (WAX_TYPE)WT;
        }


        public WAX_TYPE Wachstyp { get; private set; }


        private void SetPreis(double data)
        {
            _preis = data;
        }

        public string Preis
        {
            get
            {
                return _preis.ToString("##0.00") + " Fr";
            }
        }

        private void SetGewicht(double data)
        {
            _gewicht = data;
        }

        public string Gewicht => _gewicht.ToString("00.000") + " kg";

        public string Zeit => _dateTime.ToString("HH:mm:ss");

        public string Datum => _dateTime.ToString("dd/MM/yyyy");

        public DateTime GetDateTime()
        {
            return _dateTime;
        }
        private void SetDateTime(byte Y, byte M, byte D, byte h, byte m, byte s)
        {
            try
            {
                _dateTime = new DateTime(Y + 2000, M, D, h, m, s);
            }
            catch
            {
                _dateTime = new DateTime(2000, 01, 01, 00, 00, 00);
            }
        }









    }
}
