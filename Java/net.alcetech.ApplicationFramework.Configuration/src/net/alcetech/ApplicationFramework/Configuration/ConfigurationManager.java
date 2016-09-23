package net.alcetech.ApplicationFramework.Configuration;

import java.io.FileNotFoundException;
import java.io.IOException;

import net.alcetech.ApplicationFramework.Application;
import net.alcetech.ApplicationFramework.Command;
import net.alcetech.ApplicationFramework.CommandItem;
import net.alcetech.ApplicationFramework.CommandItems.*;
import net.alcetech.ApplicationFramework.IO.Directory;
import net.alcetech.ApplicationFramework.IO.File;
import net.alcetech.UniversalEditor.Core.*;
import net.alcetech.UniversalEditor.Core.Accessors.FileAccessor;

import net.alcetech.UniversalEditor.DataFormats.Markup.XML.*;
import net.alcetech.UniversalEditor.ObjectModels.Markup.*;

public class ConfigurationManager {
	
	private static String _configurationFileNameFilter = "*.xml";
	public static void setConfigurationFileNameFilter(String value) { _configurationFileNameFilter = value; }
	public static String getConfigurationFileNameFilter() { return _configurationFileNameFilter; }
	
	public static void initialize() {
		
		if (Application.getShortName() == null) {
			System.err.println("appfx: please call Application.setShortName() before initializing configuration");
			return;
		}
		
		String basePath = "/usr/share/" + Application.getShortName();
		Directory directory = new Directory(basePath);
		
		File[] files = directory.getFiles(getConfigurationFileNameFilter(), true);
		
		MarkupObjectModel mom = new MarkupObjectModel();
		XMLDataFormat xdf = new XMLDataFormat();
		
		for (int i = 0; i < files.length; i++) {
			
			FileAccessor fa = null;
			try {
				fa = FileAccessor.fromFile(files[i].getUnderlyingFile());
			} catch (FileNotFoundException e) {
				System.out.println("appfx: file '" + files[i].getFullPath() + "' not found");
				continue;
			}
			
			// System.out.println("appfx: loading configuration file '" + files[i].getFullPath() + "'");
			try {
				Document.load(mom, xdf, fa);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		MarkupElement[] elements = mom.getElements();
		for (int i = 0; i < elements.length; i++) {
			if (elements[i].getName().equals("ApplicationFramework")) {
				
				if (elements[i].getClass().isAssignableFrom(MarkupTagElement.class)) {
					MarkupTagElement tagMainMenu = ((MarkupTagElement)elements[i]).getTagByTagName("MainMenu");
					if (tagMainMenu != null) {
					
						MarkupTagElement tagItems = tagMainMenu.getTagByTagName("Items");
						if (tagItems != null) {
						
							MarkupTagElement[] tags = tagItems.getTags();
							for (int j = 0; j < tags.length; j++) {
								CommandItem ci = LoadCommandItemFromTag(tags[j]);
								if (ci != null) {
									Application.addMainMenuCommandItem(ci);
								}
							}
						
						}
					
					}
					

					MarkupTagElement tagCommands = ((MarkupTagElement)elements[i]).getTagByTagName("Commands");
					if (tagCommands != null) {
						MarkupTagElement[] tags = tagCommands.getTags();
						System.out.println("found " + tags.length + " Commands tags");
						for (int j = 0; j < tags.length; j++) {
							if (tags[j].getName().equals("Command")) {
								MarkupAttribute attCommandID = tags[j].getAttribute("ID");
								if (attCommandID == null) continue;
								
								Command cmd = new Command(attCommandID.getValue());
								
								MarkupTagElement[] tagItems = tags[j].getTags();
								for (int k = 0; k < tagItems.length; k++) {
									CommandItem ci = LoadCommandItemFromTag(tagItems[k]);
									if (ci == null) continue;
									cmd.addItem(ci);
								}
								
								Application.addCommand(cmd);
							}
						}
					}
				}
				
			}
		}
		
	}
	private static CommandItem LoadCommandItemFromTag(MarkupTagElement tag) {

		if (tag.getName().equals("CommandReference")) {
			MarkupAttribute attCommandID = tag.getAttribute("CommandID");
			if (attCommandID == null) return null;
			
			return new CommandReferenceCommandItem(attCommandID.getValue());
		}
		else if (tag.getName().equals("Separator")) {
			return new SeparatorCommandItem();
		}
		return null;
	}

}
