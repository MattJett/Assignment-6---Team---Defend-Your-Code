using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

/// <include file='docs.xml' path='docs/members[@name="launcher"]/Launcher/*'/>
namespace AS6_DefendYourCode
{
    public class Launcher
    {
        private static Dictionary<string, List<string>> _dictionary;

        public static void Main(params string[] args)
        {
            // test
            _dictionary = new Dictionary<string, List<string>>();
            InitializeTestInputs();
            TestInputFile();

            PromptUser();
        }

        private static void PromptUser() 
        {
            Console.WriteLine("Assignment 6: Team - Defend your code");

            InputName inputName = new InputName();
            inputName.Prompt();
            
            InputInteger inputInteger = new InputInteger();
            inputInteger.Prompt();

            InputFileNameIO inputFileNameIO = new InputFileNameIO();
            inputFileNameIO.Prompt();
            // test

            inputFileNameIO.WriteTo(inputName, inputInteger);
            //var writer = new StreamWriter(file);
            //writer.WriteLine(inputName.FirstName)
            InputPassword inputPassword = new InputPassword();
            inputPassword.Prompt();
        }

        // test
        private static void InitializeTestInputs()
        {
            using (var reader = new StreamReader( "..\\..\\..\\input.txt"))
            {
                string line, key = "a";
                while((line = reader.ReadLine()) != null)
                {
                    if(line.Length == 1 && Regex.IsMatch(line, "[a-f]"))
                    {
                        key = line;
                        if(!_dictionary.ContainsKey(key))
                        {
                            _dictionary.Add(key, new List<string>());
                        }
                    }
                    else if (line.Length > 0 && !Regex.IsMatch(line, "^\\s*$"))
                    {
                        _dictionary[key].Add(line.Trim());
                    }
                }
            }
        }

        // test
        private static void TestInputFile()
        {
            InputName inputName = new InputName();
            InputInteger inputInteger = new InputInteger();
            InputFileNameIO inputFileNameIO = new InputFileNameIO();
            InputPassword inputPassword = new InputPassword();
            List<string> valid = new List<string>();
            List<string> failed = new List<string>();
            using (var write = new StreamWriter("..\\..\\..\\output.txt"))
            {
                write.WriteLine("Test Results: ");
                foreach (var key in _dictionary.Keys)
                {
                    write.WriteLine("\n" + key + ": ");
                    foreach (var value in _dictionary[key])
                    {
                        switch (key)
                        {
                            case "a":
                                string[] name = value.Split(" ");
                                // checks first name and last name delimited by white spaces. but will add 
                                // the original to the list
                                (inputName.IsValidFirstAndLastName(name[0], name[1]) ? valid : failed).Add(value);
                                break;
                        }
                    }
                    write.WriteLine("Valid test cases: ");
                    valid.ForEach(s => write.WriteLine("\t" + s));
                    write.WriteLine("Failed test cases: ");
                    failed.ForEach(s => write.WriteLine("\t" + s));
                    valid.Clear();
                    failed.Clear();
                }
            }
        }

    }
}
