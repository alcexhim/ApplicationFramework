package net.alcetech.ApplicationFramework.Configuration;

import java.io.FileNotFoundException;
import java.io.IOException;

import net.alcetech.ApplicationFramework.Application;
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
		
		
	}

}
