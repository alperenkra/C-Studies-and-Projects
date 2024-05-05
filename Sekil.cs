using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance_Study
{
    internal class Sekil
    {
        private int alan;
        //protected int alan; 
        //temel classta değişkenleri private tanımlarsak kalıtım alan sınıflarda metod içinde o değişkenleri kullanamyoruz fakat, protected tanımlarsak kullanabiliyoruz (erişebiliyoruz)
        //.Ama protected olunca da ana classtan erişemiyoruz.
        private int x;
        private int y;
        private int cevre;

        public Sekil()
        {
            Console.WriteLine("Sekil() Cagrildi");
        }

        public Sekil(int _x,int _y)
        {
            Console.WriteLine("Sekil( "+_x +"," + _y +")" + " Cagrildi");


            x = _x;
            y = _y;
        }

        public int Alan
        {
            get
            {
                return alan;
            }
            set
            {
                alan = value;
            }
        }

        public int X
        {
            get { return x; }
            set { x = value; }
        }

        public int Y
        {
            get { return y; }
            set { y = value; }
        }

        public int Cevre
        {
            get { return cevre; }
            set { cevre = value; }
        }
        
        public void AlaniYaz()
        {
            Console.WriteLine("Koordinatlar: " + x + "," + y + " olan seklin alanı...:" + alan);
        }
    }
}
