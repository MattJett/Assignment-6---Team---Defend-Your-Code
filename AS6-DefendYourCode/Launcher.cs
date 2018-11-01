using System;
using System.IO;

/// <include file='docs.xml' path='docs/members[@name="launcher"]/Launcher/*'/>
namespace AS6_DefendYourCode
{
    public class Launcher
    {
        private static InputName _inputName = new InputName();
        private static InputInteger _inputInteger = new InputInteger();
        private static InputFileNameIO _inputFileNameIO = new InputFileNameIO();
        private static InputPassword _inputPassword = new InputPassword();

        public static void Main(params string[] args)
        {
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
            _inputPassword.Prompt();
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
    }
}
