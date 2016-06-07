package net.alcetech.ApplicationFramework.CommandItems;

import net.alcetech.ApplicationFramework.CommandItem;

public class CommandReferenceCommandItem extends CommandItem {
	
	private String _CommandID = "";
	public String getCommandID() { return _CommandID; }
	public void setCommandID(String value) { _CommandID = value; }
	
	public CommandReferenceCommandItem(String commandID) { 
		this.setCommandID(commandID);
	}

}
