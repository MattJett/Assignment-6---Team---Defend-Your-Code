using System;
using System.Numerics;

namespace AS6_DefendYourCode
{
    internal class InputInteger
    {
        internal BigInteger Num1 { get; private set; }
        internal BigInteger Num2 { get; private set; }

        internal void Prompt()
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

        internal string Sum()
        {
            // TODO: make sure its not null
            return BigInteger.Add(Num1, Num2).ToString();
        }

        internal string Multiply()
        {
            // TODO: make sure its not null
            return BigInteger.Multiply(Num1, Num2).ToString();
        }

        //test
        internal bool TestPrompt(String one, String two)
        {
            try
            {
                Num1 = BigInteger.Parse(one.Trim());
                Num2 = BigInteger.Parse(two.Trim());
            }
            catch (Exception e)
            {
                return false;
            }
            return true;
        }
    }
}
