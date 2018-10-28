using System;
using System.Collections.Generic;
using System.IO;

/// <include file='docs.xml' path='docs/members[@name="launcher"]/Launcher/*'/>
namespace AS6_DefendYourCode
{
    public class Launcher
    {
        public static Dictionary<string, List<string>> _dictionary;

        public static void Main(params string[] args)
        {
            _dictionary = new Dictionary<string, List<string>>();
            initializeTestInputs();
            PromptUser();
        }
        // TODO: TEST
        private static void PromptUser() 
        {
            Console.WriteLine("Assignment 6: Team - Defend your code");

            InputName inputName = new InputName();
            inputName.Prompt();
            
            InputInteger inputInteger = new InputInteger();
            inputInteger.Prompt();

            InputFileNameIO inputFileNameIO = new InputFileNameIO();
            inputFileNameIO.Prompt();
            FileStream file = inputFileNameIO.InputFileName;

            InputPassword inputPassword = new InputPassword();
            inputPassword.Prompt();
        }

        private static void initializeTestInputs()
        {

        }

    }
}
