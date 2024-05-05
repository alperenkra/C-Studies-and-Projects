namespace Self_Study
{
    internal class Program
    {
        static void Main(string[] args)
        {



            //SimpleObject object1 = new SimpleObject();

            //object1.Data = -32;

            //object1.printData();


            //Number number1 = new Number() { value= 5};

            //Console.WriteLine(number1.value);
            //Console.WriteLine(number1.value);

            //Car mustang = new Car("Mustang");

            //Console.WriteLine(mustang.model);


            //Console.Write("Enter Day Number: ");

            //int day = Convert.ToInt32(Console.ReadLine());

            //string dayName;

            //switch (day)
            //{

            //    case 1: dayName = "MONDAY";
            //        break;
            //    case 2: dayName = "TUESDAY";
            //        break;
            //    case 3: dayName = "WEDNESDAY";
            //        break;
            //    case 4: dayName = "THURSDAY";
            //        break;
            //    case 5: dayName = "FRIDAY";
            //        break;
            //    case 6: dayName = "SATURDAY";
            //        break;
            //    case 7: dayName = "SUNDAY";
            //        break;
            //    default: dayName = "ERROR";
            //        break;
            //}


            //Console.WriteLine("The day of the week is " + dayName);


        }

        class StringClass
        {

            public StringClass()
            {
                
            }
            private string word;

            public string _word
            {
                set { word = value; }
                get { return word; }
            }

            public string convertToLower(string input)
            {
                word = word.ToLower
            }
        }




        //class SimpleObject 
        //{
        //    private int mData = 5;

        //    public int Data
        //    {
        //        set { mData = value; }
        //        get { return mData; }
        //    }

        //    public void printData() 
        //    {
        //        Console.WriteLine(Data);            
        //    }
            
        //}

        //class Number
        //{
        //    public int value { init; get; } = 0;

        //    public Number()
        //    { }
        //}

        //class Car
        //{

        //    public string model;

        //    public Car(string modelName)
        //    {

        //        model = modelName;
        //    }

        //}

        //class anotherObject()
        //{
        //    private int data;

        //    public anotherObject() { }

        //    public anotherObject(int _data)
        //    {
        //        data = _data;
        //    }

        //    public void SetValue(int _data)
        //    {
        //        data = _data;
        //    }
        //}
    }
}
