namespace Inheritance_Study
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Kare kare = new Kare();
            kare.X = 10;
            kare.Y = 20;
            kare.Alan = 100;

            Kare kare1 = new Kare(22,33);

            kare.AlaniYaz();

            Console.WriteLine("------------");            

            Dİkdortgen dikdortgen = new Dİkdortgen();

            dikdortgen.X = 30;
            dikdortgen.Y = 40;
            dikdortgen.Alan = 300;

            dikdortgen.AlaniYaz();


            
        }
    }
}
