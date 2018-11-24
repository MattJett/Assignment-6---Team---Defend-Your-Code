// Hung Auduong
// Matthew Jetts
// C#-Implementation

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
				if (!ValidateInput(originalPassword = ReadLine().Trim()))
					throw new Exception();
				originalPassword = SecurePassword(originalPassword);
				StorePassword(originalPassword);
				Console.WriteLine("PASSWORD is now ENCRPYTED and STORED in 'account.txt'.");

				int tries = 3;
				while (tries > 0)
				{
					Console.Write("Re-enter Password ({0} tries remaining): ", tries);
					if (ValidateInput(newPassword = ReadLine().Trim()))
					{
						newPassword = SecurePassword(newPassword);
						if (ValidatePassword(newPassword))
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
						Console.WriteLine("Re-entered password did not follow the password format!! Try again!");
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

		private void StorePassword(string encryptedPassword)
		{
			var file = new FileStream("..\\..\\..\\" + "account.txt", FileMode.Create, FileAccess.Write);
			using (var stream = new StreamWriter(file))
			{
				try
				{
					stream.Write("{0}\n{1}\n", Convert.ToBase64String(_salt), encryptedPassword);
				}
				catch (Exception e)
				{
					Console.WriteLine("There was an error in storing your password: ");
					Errors.Add("InputPassword - StorePassword() " + e.ToString());
				}
				finally
				{
					stream.Close();
					file.Close();
				}
			}
		}

		private bool ValidatePassword(string encryptedPassword)
		{
			string readSalt = null;
			string readHash = null;
			var lines = File.ReadAllLines("..\\..\\..\\" + "account.txt", Encoding.UTF8);
			try
			{
				readSalt = lines[0];
				readHash = lines[1];
				return Convert.ToBase64String(_salt).Equals(readSalt) && encryptedPassword.Equals(readHash) ? true : false;
			}
			catch (Exception e)
			{
				Errors.Add("InputPassword - ValidatePassword() ");
				throw new Exception("Error reading from file: ");
			}
		}

		private string SecurePassword(string password)
		{
			if (_salt == null)
				GenerateSalt();
			using (var hmac = new HMACSHA256(_salt))
			{
				return Convert.ToBase64String(hmac.ComputeHash(new UTF8Encoding().GetBytes(password + _salt)));
			}
		}

		private bool ValidateInput(string s)
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
	}
}
