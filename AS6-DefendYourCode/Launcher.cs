using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

/// <include file='docs.xml' path='docs/members[@name="launcher"]/Launcher/*'/>
namespace AS6_DefendYourCode
{
    public class Launcher
    {
        private static Dictionary<string, List<string>> _testDictionary;
        private static InputName _inputName = new InputName();
        private static InputInteger _inputInteger = new InputInteger();
        private static InputFileNameIO _inputFileNameIO = new InputFileNameIO();
        private static InputPassword _inputPassword = new InputPassword();

        public static void Main(params string[] args)
        {
            // test
            _testDictionary = new Dictionary<string, List<string>>();
            //TestInitializeInputs();
            //TestInputFile();
            PromptUser();
            WriteResultToFile();
            WriteErrorsToFile();
        }


        private static void PromptUser() 
        {
            Console.WriteLine("Assignment 6: Team - Defend your code");
            _inputName.Prompt();
            _inputInteger.Prompt();
            _inputFileNameIO.Prompt();
            _inputPassword.HungPrompt();
        }

        private static void WriteResultToFile()
        {
            _inputFileNameIO.WriteTo(_inputName, _inputInteger);
        }

        private static void WriteErrorsToFile()
        {
            using (var write = new StreamWriter("..\\..\\..\\error.txt"))
            {
                _inputName.Errors.ForEach(err => write.WriteLine(err));
                _inputInteger.Errors.ForEach(err => write.WriteLine(err));
                _inputFileNameIO.Errors.ForEach(err => write.WriteLine(err));
                _inputPassword.Errors.ForEach(err => write.WriteLine(err));

            }
        }

        #region Testing helper method
        // test
        private static void TestInitializeInputs()
        {
            using (var reader = new StreamReader( "..\\..\\..\\input.txt"))
            {
                string line, key = "a";
                while((line = reader.ReadLine()) != null)
                {
                    if(line.Length == 1 && Regex.IsMatch(line, "[a-f]"))
                    {
                        key = line;
                        if(!_testDictionary.ContainsKey(key))
                        {
                            _testDictionary.Add(key, new List<string>());
                        }
                    }
                    else if (line.Length > 0 && !Regex.IsMatch(line, "^\\s*$"))
                    {
                        _testDictionary[key].Add(line.Trim());
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
                foreach (var key in _testDictionary.Keys)
                {
                    write.WriteLine("\n" + key + ": ");
                    var array = _testDictionary[key].ToArray();
                    for(int i = 0; i < array.Length; i++)
                    {
                        switch(key)
                        {
                            case "a":
                                i++;
                                (inputName.TestPrompt(array[i - 1], array[i]) ? valid : failed).Add(array[i - 1] + " " + array[i]);
                                break;
                            case "b":
                                i++;
                                if(inputInteger.TestPrompt(array[i - 1], array [i]))
                                {
                                    valid.Add(array[i - 1]);
                                    valid.Add(array[i]);
                                }
                                else
                                {
                                    failed.Add(array[i - 1]);
                                    failed.Add(array[i]);
                                }
                                break;
                            case "c":
                                (inputFileNameIO.TestPrompt(array[i]) ? valid : failed).Add(array[i]);
                                break;
                            case "d":
                                (inputPassword.TestPrompt(array[i]) ? valid : failed).Add(array[i]);
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
        #endregion
    }
}
