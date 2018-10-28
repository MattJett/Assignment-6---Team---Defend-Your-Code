using System;
using System.Numerics;

namespace AS6_DefendYourCode
{
    internal class InputInteger
    {
        public BigInteger Num1 { get; private set; }
        public BigInteger Num2 { get; private set; }

        public void Prompt()
        {
            try
            {
                Console.Write("\nEnter First Number: ");
                Num1 = BigInteger.Parse(Console.ReadLine().Trim());
                Console.Write("\nEnter Second Number: ");
                Num2 = BigInteger.Parse(Console.ReadLine().Trim());
            }
            catch (Exception e)
            {
                Console.WriteLine("There was an error in your integer input: ");
                Console.WriteLine(e);
                Prompt();
            } 
        }

        public string Sum()
        {
            // TODO: make sure its not null
            return BigInteger.Add(Num1, Num2).ToString();
        }

        public string Multiply()
        {
            // TODO: make sure its not null
            return BigInteger.Multiply(Num1, Num2).ToString();
        }
    }
}
