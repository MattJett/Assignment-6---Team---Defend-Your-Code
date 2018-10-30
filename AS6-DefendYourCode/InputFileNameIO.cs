using System;
using System.IO;
using System.Numerics;

namespace AS6_DefendYourCode
{
    internal class InputFileNameIO
    {
        internal FileStream InputFileName { get; private set; }
        internal FileStream OutputFileName { get; private set; }

        internal void Prompt()
        {
            // TODO: Limit file extension type and directory location!
            try
            {
                Console.Write("\nEnter Input File Name: ");
                InputFileName = new FileStream("..\\..\\..\\" + Console.ReadLine(), FileMode.OpenOrCreate, FileAccess.Read);
                //InputFileName.Close();
                Console.Write("\nEnter Output File Name: ");
                OutputFileName = new FileStream("..\\..\\..\\" + Console.ReadLine(), FileMode.OpenOrCreate, FileAccess.Write);
                InputFileName.Close();
                OutputFileName.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("There was an error in your file input: ");
                Console.WriteLine(e);
                Prompt();
            }
        }

        // TODO: Read input file and then go thru it and print it on the output file
        internal void WriteTo(InputName name, InputInteger integer)
        {
            try
            {
                using (var stream = new StreamWriter(OutputFileName.Name))
                {
                    stream.WriteLine("{0}, {1}\nSum: {2}\nProduct: {3}\n", new object[] { name.LastName, name.FirstName, integer.Sum(), integer.Multiply() });
                }
            }
            catch (IOException)
            {
                throw new IOException(); // TODO: fix?
            }
        }

        internal void ReadFrom()
        {
            using (var stream = new StreamReader("..\\..\\..\\" + InputFileName))
            {
                try
                {
                    Console.WriteLine(stream.ReadLine());
                }
                catch (IOException)
                {
                    throw new IOException(); // TODO: fix?
                }
            }
        }
        
        // TODO: this right her ewill check if its a txt, and location. (like how big integer class was "supposed" to be)
        internal bool TestPrompt(string s)
        {
            return true;
        }

    }
}
