package net.alcetech.ApplicationFramework;

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
	
	private static String _ShortName = "";
	public static String getShortName() { return _ShortName; }
	public static void setShortName(String value) { _ShortName = value; }

	private static ArrayList<Command> _commands = new ArrayList<Command>();
	public static void addCommand(Command item) {
		_commands.add(item);
	}
	public static Command getCommand(String commandID) {
		for (int i = 0; i < _commands.size(); i++) {
			Command item = _commands.get(i);
			if (item.getID().equals(commandID)) return item;
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

	
	private static ArrayList<CommandItem> _mainMenuCommandItems = new ArrayList<CommandItem>();
	public static CommandItem[] getMainMenuCommandItems() {
		CommandItem[] array = new CommandItem[_mainMenuCommandItems.size()];
		_mainMenuCommandItems.toArray(array);
		return array;
	}
	public static void addMainMenuCommandItem(CommandItem item) {
		_mainMenuCommandItems.add(item);
	}
	
	private static Hashtable<Command, ArrayList<CommandListener>> _commandBindings = new Hashtable<Command, ArrayList<CommandListener>>();
	public static void bindCommand(Command item, CommandListener listener) {
		if (item == null) {
			System.out.println("appfx: Application::bindCommand() - item is null\n");
			return;
		}
		
		if (!_commandBindings.containsKey(item))
		{
			_commandBindings.put(item, new ArrayList<CommandListener>());
		}
		
		ArrayList<CommandListener> bindings = _commandBindings.get(item);
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
