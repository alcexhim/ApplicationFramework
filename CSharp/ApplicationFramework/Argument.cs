using System;

namespace ApplicationFramework
{
	public class Argument
	{
		public class ArgumentCollection
			: System.Collections.ObjectModel.Collection<Argument>
		{

			public Argument Add(string name, string description = null, char mnemonic = '\0')
			{
				Argument arg = new Argument ();
				arg.Name = name;
				arg.Description = description;
				arg.Mnemonic = mnemonic;
				Add (arg);
				return arg;
			}

			public Argument this[string name]
			{
				get {
					foreach (Argument arg in this) {
						if (arg.Name == name)
							return arg;
					}
					return null;
				}
			}
			public Argument this[char mnemonic]
			{
				get {
					foreach (Argument arg in this) {
						if (arg.Mnemonic == mnemonic)
							return arg;
					}
					return null;
				}
			}


		}

		private string mvarName = null;
		public string Name { get { return mvarName; } set { mvarName = value; } }

		private char mvarMnemonic = '\0';
		public char Mnemonic { get { return mvarMnemonic; } set { mvarMnemonic = value; } }

		private string mvarDescription = null;
		public string Description { get { return mvarDescription; } set { mvarDescription = value; } }

		private string mvarValue = null;
		public string Value { get { return mvarValue; } set { mvarValue = value; } }

		private bool mvarIsSet = false;
		public bool IsSet { get { return mvarIsSet; } set { mvarIsSet = value; } }

	}
}

