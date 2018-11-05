// Hung Auduong
// Matthew Jetts
// C#-Implementation

using System.IO;
using System;
using System.Linq;
using System.Collections.Generic;

namespace AS6_DefendYourCode
{
    internal class InputName
    {
        private const int READLINE_BUFFER_SIZE = 50;

        internal string FirstName { get; private set; }
        internal string LastName { get; private set; }
        internal List<string> Errors { get; private set; }

        private static string ReadLine()
        {
            Console.SetIn(new StreamReader(Console.OpenStandardInput(READLINE_BUFFER_SIZE)));
            return Console.ReadLine();
        }

        internal void Prompt()
        {
            try
            {
                if(Errors == null)
                    Errors = new List<string>();
                Console.Write("\nEnter First Name: ");
                FirstName = ReadLine().Trim();
                Console.Write("\nEnter Last Name: ");
                LastName = ReadLine().Trim();
                if (!TestPrompt(FirstName, LastName)) throw new Exception("Name length out of bound!");
            }
            catch (Exception e)
            {
                Console.WriteLine("There was an error in your name input: ");
                Console.WriteLine(e);
                Errors.Add("InputName - Prompt() " + e.ToString());
                Prompt();
            }
        }

        private bool TestPrompt(string first, string last)
        {
            return Enumerable.Range(1, 50).Contains(first.Length) &&
                Enumerable.Range(1, 50).Contains(last.Length);
        }

    }
}
