using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance_Study
{
    internal class Kare : Sekil
    {
        private int boyut;

        //public Kare():base(11,22)
        //{
        //    Console.WriteLine("Kare() Cagrildi");
        //}

        public Kare()
        {
            Console.WriteLine("kare cagirildi");
        }

        public Kare(int px,int py):base(px,py)
        {
            Console.WriteLine("Kare (" + px + "," + py + ") cagirildi");

        }

        public int Boyut
        {
            get
            {
                return boyut;
            }
            set
            {
                boyut = value;
            }
        }

        public int AlanHesapla()
        {
            //temel classta değişkenleri private tanımlarsak kalıtım alan sınıflarda metod içinde o değişkenleri kullanamyoruz fakat, protected tanımlarsak kullanabiliyoruz(erişebiliyoruz)
            return boyut * boyut;
        }
    }
}
