using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace AS6_DefendYourCode
{
    internal class InputFileNameIO
    {
        //internal FileStream InputFileName { get; private set; }
        //internal FileStream OutputFileName { get; private set; }
        internal string InputFileName { get; private set; }
        internal string OutputFileName { get; private set; }

        internal void Prompt()
        {
            // TODO: Limit file extension type and directory location!
            try
            {
                Console.Write("\nEnter Input File Name: ");
                InputFileName = Console.ReadLine().Trim();
                Console.Write("\nEnter Output File Name: ");
                OutputFileName = Console.ReadLine().Trim();
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
            //FileStream fout = new FileStream("..\\..\\..\\" + OutputFileName, FileMode.OpenOrCreate, FileAccess.Write);
            using (var stream = new StreamWriter(new FileStream("..\\..\\..\\" + OutputFileName, FileMode.OpenOrCreate, FileAccess.Write)))
            {
                try
                {
                    stream.WriteLine("{0}, {1}\nSum: {2}\nProduct: {3}", new object[] {
                        name.LastName, name.FirstName, integer.Sum(), integer.Multiply()
                    });
                    stream.Close();
                    WriteFromInput();
                }
                catch (IOException)
                {
                    throw new IOException(); // TODO: fix?
                }
            }
        }

        private void WriteFromInput() 
        {
            List<string> result = new List<string>();
            using (var reader = new StreamReader("..\\..\\..\\" + InputFileName))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    result.Add(line);
                }
            }
            using (StreamWriter writer = File.AppendText("..\\..\\..\\" + OutputFileName))
            {
                result.ForEach(s => writer.WriteLine(s));
            }
        }
        
        // TODO: this right her ewill check if its a txt, and location. (like how big integer class was "supposed" to be)
        internal bool TestPrompt(string s)
        {
            return true;
        }
    }
}
