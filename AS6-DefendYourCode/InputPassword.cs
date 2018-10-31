using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Security.Cryptography;
using System.Text.RegularExpressions;

namespace AS6_DefendYourCode
{
    internal class InputPassword
    {
        private const int READLINE_BUFFER_SIZE = 12;

        internal List<string> Errors { get; private set; }
		private byte[] _salt;

        private static string ReadLine()
        {
            Console.SetIn(new StreamReader(Console.OpenStandardInput(READLINE_BUFFER_SIZE)));
            return Console.ReadLine();
        }

        internal void Prompt()
        {
			string originalPassword;
			string newPassword;
            try
            {
                if (Errors == null)
                    Errors = new List<string>();
                Console.Write("\nEnter A Password (must be between 6-12 characters long): ");
                originalPassword = ReadLine().Trim();
                if (!HungValidatePasswordInput(originalPassword)) throw new Exception();
				GenerateSalt();
                originalPassword = SecurePassword(originalPassword);
                Console.WriteLine("PASSWORD is now ENCRPYTED");
                int tries = 3;
                while (tries > 0)
                {
                    Console.Write("Re-enter Password ({0} tries remaining): ", tries);
                    newPassword = ReadLine().Trim();
                    if (HungValidatePasswordInput(newPassword))
                    {
                        newPassword = SecurePassword(newPassword);
						if (originalPassword.Equals(newPassword))
						{
							tries = 0;
							Console.WriteLine("\nPASS\n");
						}
						else
						{
							tries -= 1;
							Console.WriteLine("\nFAIL\n");
						}
                    }
                    else
                    {
                        Console.WriteLine("2nd Password did not follow the password format!! Try again!");
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("There was an error in your password input: ");
                Console.WriteLine(e);
                Errors.Add("InputPassword - Prompt() " + e.ToString());
                Prompt();
            }
			finally
			{
				originalPassword = null;
				newPassword = null;
			}
        }

        private string SecurePassword(string password)
        {
            var passwordInBytes = new UTF8Encoding().GetBytes(password);
			return Convert.ToBase64String(GenerateSaltedHash(passwordInBytes, _salt));
        }

        private bool HungValidatePasswordInput(string s)
        {
            return Regex.IsMatch(s, @"^[\w\!\@\#\$\%\^\&\*\)\(\-\+\=\]\[\}\{\]\|\>\<\?\~\`]{6,12}$");
        }

		private void GenerateSalt()
		{
			using (var hash = new RNGCryptoServiceProvider())
			{
				hash.GetBytes(_salt = new byte[10]);
			}
		}

		private byte[] GenerateSaltedHash(byte[] password, byte[] salt)
		{
			using (var hmac = new HMACSHA256(salt))
			{
				return hmac.ComputeHash(password);
			}
		}
	}
}
