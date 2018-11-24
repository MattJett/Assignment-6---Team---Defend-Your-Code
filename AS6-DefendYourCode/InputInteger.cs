// Hung Auduong
// Matthew Jetts
// C#-Implementation

using System;
using System.Collections.Generic;
using System.Numerics;

namespace AS6_DefendYourCode
{
    internal class InputInteger
    {
        internal BigInteger Num1 { get; private set; }
        internal BigInteger Num2 { get; private set; }
        internal List<string> Errors { get; private set; }

        internal void Prompt()
        {
            try
            {
                if (Errors == null)
                    Errors = new List<string>();
                Console.Write("\nEnter First Number: ");
                Num1 = BigInteger.Parse(Console.ReadLine().Trim());
                Console.Write("\nEnter Second Number: ");
                Num2 = BigInteger.Parse(Console.ReadLine().Trim());
            }
            catch (Exception e)
            {
                Console.WriteLine("There was an error in your integer input: ");
                Errors.Add("InputInteger - Prompt() " + e.ToString());
                Prompt();
            }
        }

        internal string Sum()
        {
            if (this == null || Num1 == null || Num2 == null)
                Prompt();
            return BigInteger.Add(Num1, Num2).ToString();
        }

        internal string Multiply()
        {
            if (this == null || Num1 == null || Num2 == null)
                Prompt();
            return BigInteger.Multiply(Num1, Num2).ToString();
        }
    }
}
