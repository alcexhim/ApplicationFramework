using System;
using System.Collections.Generic;

namespace ApplicationFramework
{
	public class Application
	{

		private static Argument.ArgumentCollection mvarArguments = new Argument.ArgumentCollection();
		public static Argument.ArgumentCollection Arguments { get { return mvarArguments; } }

		private static System.Collections.Specialized.StringCollection mvarOperands = new System.Collections.Specialized.StringCollection ();
		public static System.Collections.Specialized.StringCollection Operands { get { return mvarOperands; } }

		public static string[] GetBasePaths()
		{
			List<string> basePaths = new List<string> ();

			// the Common Application Data folder
			basePaths.Add (String.Join (System.IO.Path.DirectorySeparatorChar.ToString (), new string[] {
				System.Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData),
				(System.Environment.OSVersion.Platform == PlatformID.MacOSX || System.Environment.OSVersion.Platform == PlatformID.Unix) ? "alyx" : "Mike Becker's Software" + System.IO.Path.DirectorySeparatorChar.ToString() + "Alyx"
			}));

			// the location of the entry assembly
			basePaths.Add (String.Join (System.IO.Path.DirectorySeparatorChar.ToString (), new string[] {
				System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetEntryAssembly().Location)
			}));

			return basePaths.ToArray ();
		}

		public static void Initialize()
		{
			string[] arguments = Environment.GetCommandLineArgs ();
			bool argsDone = false;

			for (int i = 1; i < arguments.Length; i++) {
				switch (Environment.OSVersion.Platform) {
					case PlatformID.MacOSX:
					case PlatformID.Unix:
					{
						// format is --name=value or -n value
						if (arguments [i] == "--") {
							argsDone = true;
							continue;
						}

						if (argsDone) {
							mvarOperands.Add (arguments [i]);
						} else {
							Argument arg = null;
							if (arguments [i].StartsWith ("--")) {
								string nameAndPossiblyValue = arguments [i].Substring (2);
								string name = nameAndPossiblyValue;
								string value = null;
								if (nameAndPossiblyValue.Contains ("=")) {
									name = nameAndPossiblyValue.Substring (0, nameAndPossiblyValue.IndexOf ('='));
									value = nameAndPossiblyValue.Substring (nameAndPossiblyValue.IndexOf ('=') + 1);
								}
								arg = mvarArguments [name];
								if (arg == null) {
									arg = mvarArguments.Add (name, null, '\0');
								}
								arg.Value = value;
							} else if (arguments [i].StartsWith ("-")) {
								if (arguments [i].Length == 2) {
									// single char argument name
									arg = mvarArguments [arguments [i] [1]];
								} else {
									// old-style -nvalue
									
								}
							}
							if (arg != null) {
								arg.IsSet = true;
							}
						}
						break;
					}
					case PlatformID.Win32NT:
					case PlatformID.Win32S:
					case PlatformID.Win32Windows:
					case PlatformID.WinCE:
					case PlatformID.Xbox:
					{
						break;
					}
				}
			}
		}

		private static string mvarDescription = null;
		public static string Description { get { return mvarDescription; } set { mvarDescription = value; } }

		private static Func<int> mvarMainLoop = null;
		public static Func<int> MainLoop
		{
			get { return mvarMainLoop; }
			set { mvarMainLoop = value; }
		}

		public static int Run()
		{
			if (mvarArguments ["help"] != null) {
				if (mvarArguments ["help"].IsSet) {
					Console.WriteLine ("Usage: " + System.Reflection.Assembly.GetEntryAssembly ().GetName ().Name + " [OPTIONS]");
					if (mvarDescription != null) {
						Console.WriteLine (mvarDescription);
					}
					Console.WriteLine ();

					int longestNameLength = 0;
					foreach (Argument arg in mvarArguments) {
						int namelen = 0;
						if (arg.Mnemonic != '\0') {
							namelen += 2;
							if (arg.Name != null) {
								namelen += 2;
							}
						}
						if (arg.Name != null) {
							namelen += arg.Name.Length + 2;
						}

						if (namelen > longestNameLength)
							longestNameLength = namelen;
					}

					foreach (Argument arg in mvarArguments) {
						int namelen = 0;

						Console.Write ("  ");

						if (arg.Mnemonic != '\0') {
							Console.Write ("-" + arg.Mnemonic.ToString ());
							namelen += 2;
							if (arg.Name != null) {
								Console.Write (", ");
								namelen += 2;
							}
						} else {
							Console.Write ("    ");
							namelen += 4;
						}
						if (arg.Name != null) {
							Console.Write ("--");
							Console.Write (arg.Name);
							namelen += arg.Name.Length + 2;
						}

						Console.Write (new String (' ', (longestNameLength - namelen) + 8));

						if (arg.Description != null) {
							Console.Write (arg.Description);
						}
						Console.WriteLine ();
					}
					return 0;
				}
			}

			if (mvarMainLoop != null)
			{
				return mvarMainLoop ();
			}
			return 0;
		}

	}
}

