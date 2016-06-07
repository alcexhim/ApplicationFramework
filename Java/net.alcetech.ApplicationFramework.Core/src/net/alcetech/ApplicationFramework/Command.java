package net.alcetech.ApplicationFramework;

import java.util.ArrayList;

public class Command {
	
	private String _ID;
	public String getID() { return _ID; }
	public void setID(String value) { _ID = value; }
	
	private String _Title;
	public String getTitle() { return _Title; }
	public void setTitle(String value) { _Title = value; }
	
	private ArrayList<CommandItem> _Items = new ArrayList<CommandItem>();
	public void addItem(CommandItem item) {
		_Items.add(item);
	}
	public CommandItem[] getItems() {
		CommandItem[] array = new CommandItem[_Items.size()];
		_Items.toArray(array);
		return array;
	}

	public Command(String id) {
		this(id, id, null);
	}
	public Command(String id, String title) {
		this(id, title, null);
	}
	public Command(String id, String title, CommandItem[] items) {
		
		this.setID(id);
		this.setTitle(title);
		
		if (items != null) {
			for (int i = 0; i < items.length; i++) {
				this.addItem(items[i]);
			}
		}
	}
}
