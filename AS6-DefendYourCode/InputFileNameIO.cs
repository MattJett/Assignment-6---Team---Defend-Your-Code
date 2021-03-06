﻿// Hung Auduong
// Matthew Jetts
// C#-Implementation

using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

namespace AS6_DefendYourCode
{
    internal class InputFileNameIO
    {
        internal string InputFileName { get; private set; }
        internal string OutputFileName { get; private set; }
        private List<string> _originalInput = new List<string>();
        internal List<string> Errors { get; private set; }

        internal void Prompt()
        {
            try
            {
                if (Errors == null)
                    Errors = new List<string>();
                Console.Write("\nEnter Input File Name: ");
                InputFileName = Console.ReadLine().Trim();
                if (!TestPrompt(InputFileName)) throw new Exception("Input file incorrect format.");

                Console.Write("\nEnter Output File Name: ");
                OutputFileName = Console.ReadLine().Trim();
                if (!TestPrompt(OutputFileName) || InputFileName.Equals(OutputFileName)) throw new Exception("Output file incorrect format.");
            }
            catch (Exception e)
            {
                Console.WriteLine("There was an error in your file input: ");
                Console.WriteLine("Only .txt files in this directory are accepted and only use [A-z0-9 or !)( -] are valid characters to use, example input: Abc9!.txt");
                Errors.Add("InputFileNameIO - Prompt() " );
                Prompt();
            }
        }

        internal void WriteTo(InputName name, InputInteger integer)
        {
            SaveOriginalInputFileContent();
            if (!File.Exists("..\\..\\..\\" + OutputFileName))
            {
                FileStream fs = File.Create("..\\..\\..\\" + OutputFileName);
                fs.Close();
            }
            using (var stream = new StreamWriter("..\\..\\..\\" + OutputFileName))
            {
                try
                {
                    stream.WriteLine("{0}, {1}\nSum: {2}\nProduct: {3}", new object[] {
                        name.LastName, name.FirstName, integer.Sum(), integer.Multiply()
                    });
                    _originalInput.ForEach(s => stream.WriteLine(s));
                }
                catch (Exception e)
                {
                    Console.WriteLine("There was an issue writing Files. Lets pick 2 new files: ");
                    Errors.Add("InputFileNameIO - WriteTo(InputName name, InputInteger integer) " + e.ToString());
                    Prompt();
					throw new IOException();
                }
            }
        }

        private void SaveOriginalInputFileContent() 
        {
            if (!File.Exists("..\\..\\..\\" + InputFileName))
            {
                FileStream fs = File.Create("..\\..\\..\\" + InputFileName);
                fs.Close();
            }
            using (var reader = new StreamReader("..\\..\\..\\" + InputFileName))
            {
				try
				{
					string line;
					while ((line = reader.ReadLine()) != null)
						_originalInput.Add(line);
				}
				catch (Exception e)
				{
					Console.WriteLine("There was an issue copying content over: ");
					Errors.Add("InputFileNameIO - SaveOriginalInputFileContent() " + e.ToString());
					throw new IOException();
				}
                
            }
        }
		
        private bool TestPrompt(string fileName)
        {
            return Regex.IsMatch(fileName, @"^[\w!)( -]+\.txt$") && !fileName.Contains("error.txt") && !fileName.Contains("account.txt") ;
        }
    }
}
