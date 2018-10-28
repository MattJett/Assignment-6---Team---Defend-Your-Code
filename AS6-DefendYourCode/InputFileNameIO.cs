using System;
using System.IO;

namespace AS6_DefendYourCode
{
    public class InputFileNameIO
    {
        public FileStream InputFileName { get; private set; }
        public FileStream OutputFileName { get; private set; }

        public void Prompt()
        {
            try
            {
                Console.Write("\nEnter Input File Name: ");
                InputFileName = new FileStream(Console.ReadLine(), FileMode.OpenOrCreate, FileAccess.Read);
                Console.Write("\nEnter Output File Name: ");
                OutputFileName = new FileStream(Console.ReadLine(), FileMode.OpenOrCreate, FileAccess.Write);
            }
            catch (Exception e)
            {
                Console.WriteLine("There was an error in your file input: ");
                Console.WriteLine(e);
                Prompt();
            }
        }
    }
}
