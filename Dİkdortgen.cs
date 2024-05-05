using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance_Study
{
    internal class Dİkdortgen:Sekil
    {
        private int genislik;
        private int yukseklik;

        public int Genislik
        {
            get
            {
                return genislik;
            }
            set
            {
                genislik = value;
            }
        }

        public int Yukseklik
        {
            get
            {
                return yukseklik;
            }
            set
            {
                yukseklik = value;
            }
        }
    }
}
