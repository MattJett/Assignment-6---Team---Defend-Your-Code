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

        internal void WriteTo(InputName name, InputInteger integer)
        {
            using (var stream = new StreamWriter("..\\..\\..\\" + OutputFileName))
            {
                try
                {
                    stream.WriteLine("{0}, {1}\nSum:{2}\nProduct:{3}\n", new object[]{name.LastName, name.FirstName, integer.Sum(), integer.Multiply()});
                }
                catch (IOException)
                {
                    throw new IOException(); // TODO: fix?
                }
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
    }
}
