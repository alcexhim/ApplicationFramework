package net.alcetech.ApplicationFramework.Configuration;

import java.io.FileNotFoundException;

import net.alcetech.ApplicationFramework.Application;
import net.alcetech.ApplicationFramework.IO.Directory;
import net.alcetech.ApplicationFramework.IO.File;
import net.alcetech.UniversalEditor.Document;
import net.alcetech.UniversalEditor.Accessors.FileAccessor;

import net.alcetech.UniversalEditor.DataFormats.Markup.XML.*;
import net.alcetech.UniversalEditor.ObjectModels.Markup.*;

public class ConfigurationManager {
	
	public static void initialize() {
		
		String basePath = "/usr/share/" + Application.getShortName();
		Directory directory = new Directory(basePath);
		
		File[] files = directory.getFiles("*.uexml", true);
		
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
			Document.load(mom, xdf, fa);
		}
		
		
	}

}
