package net.alcetech.ApplicationFramework.Core;

import java.util.ArrayList;
import java.util.Hashtable;

public class Application {
	private static String[] _args = new String[0];
	public static void initialize(String[] args) {
		Application._args = args;
	}
	
	private static String _Title = "";
	public static String getTitle() { return _Title; }
	public static void setTitle(String value) { _Title = value; }

	private static ArrayList<Command> _commands;
	public static void addCommand(Command item) {
		_commands.add(item);
	}
	public static Command getCommand(String name) {
		for (int i = 0; i < _commands.size(); i++) {
			Command item = _commands.get(i);
			if (item.getName().equals(name)) return item;
		}
		return null;
	}
	
	public static boolean executeCommand(Command item) {
		if (item == null) return false;
	
		if (item.getID().equals("FileExit"))
		{
			System.exit(0);
			return true;
		}
		
		return false;
	}

	
	private static ArrayList<CommandItem> _mainMenuCommandItems;
	public static CommandItem[] getMainMenuCommandItems() {
		CommandItem[] array = new CommandItem[_mainMenuCommandItems.size()];
		_mainMenuCommandItems.toArray(array);
		return array;
	}
	public static void addMainMenuCommandItem(CommandItem item) {
		_mainMenuCommandItems.add(item);
	}
	
	private static Hashtable<Command, ArrayList<ICommandListener>> _commandBindings = new Hashtable<Command, ArrayList<ICommandListener>>();
	public static void bindCommand(Command item, ICommandListener listener) {
		if (item == null) {
			System.out.println("appfx: Application::bindCommand() - item is null\n");
			return;
		}
		
		if (!_commandBindings.containsKey(item))
		{
			_commandBindings.put(item, new ArrayList<ICommandListener>());
		}
		
		ArrayList<ICommandListener> bindings = _commandBindings.get(item);
		bindings.add(listener);
	}
	
	public static void start() {
		
	}
	public static void stop() {
		stop(0);
	}
	public static void stop(int exitCode) {
		System.exit(exitCode);
	}

}
