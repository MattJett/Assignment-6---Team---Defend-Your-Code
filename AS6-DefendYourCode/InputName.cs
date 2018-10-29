using System.IO;
using System;

namespace AS6_DefendYourCode
{
    internal class InputName
    {
        private const int READLINE_BUFFER_SIZE = 50;

        public string FirstName { get; private set; }
        public string LastName { get; private set; }

        private static string ReadLine()
        {
            // TODO: Test to see if this works
            Console.SetIn(new StreamReader(Console.OpenStandardInput(READLINE_BUFFER_SIZE)));
            return Console.ReadLine();
        }

        //public void Prompt()
        //{
        //    try
        //    {
        //        Console.Write("\nEnter First Name: ");
        //        FirstName = ReadLine().Trim();
        //        Console.Write("\nEnter Last Name: ");
        //        LastName = ReadLine().Trim();
        //    }
        //    catch (Exception e)
        //    {
        //        Console.WriteLine("There was an error in your name input: ");
        //        Console.WriteLine(e);
        //        Prompt();
        //    }
        //}

        // this way we can test from file by calling IsValidFirstAndLastName method.
        public void Prompt()
        {
            Console.Write("\nEnter First Name: ");
            FirstName = ReadLine().Trim();
            Console.Write("\nEnter Last Name: ");
            LastName = ReadLine().Trim();
            if(!IsValidFirstAndLastName(FirstName, LastName))
            {
                Console.WriteLine("There was an error in your name input: ");
                Prompt();
            }
        }

        public bool IsValidFirstAndLastName(string first, string last)
        {
            return true;
        }

    }
}
