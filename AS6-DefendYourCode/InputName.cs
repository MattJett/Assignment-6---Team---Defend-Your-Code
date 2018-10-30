using System.IO;
using System;

namespace AS6_DefendYourCode
{
    internal class InputName
    {
        private const int READLINE_BUFFER_SIZE = 50; // TODO: test to see if we need 51 or 50?

        internal string FirstName { get; private set; }
        internal string LastName { get; private set; }

        private static string ReadLine()
        {
            // TODO: Test to see if this works
            Console.SetIn(new StreamReader(Console.OpenStandardInput(READLINE_BUFFER_SIZE)));
            return Console.ReadLine();
        }

        internal void Prompt()
        {
            try
            {
                Console.Write("\nEnter First Name: ");
                FirstName = ReadLine().Trim();
                Console.Write("\nEnter Last Name: ");
                LastName = ReadLine().Trim();
                // test ask Tom if needed for regex?
                if (!TestPrompt(FirstName, LastName)) throw new Exception();
            }
            catch (Exception e)
            {
                Console.WriteLine("There was an error in your name input: ");
                Console.WriteLine(e);
                Prompt();
            }
        }

        // test
        public bool TestPrompt(string first, string last)
        {
            return true;
        }

    }
}
