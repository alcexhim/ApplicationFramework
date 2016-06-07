package net.alcetech.ApplicationFramework.IO;

public class File extends FileSystemObject {
	
	public File(String fullPath) {
		this.setFullPath(fullPath);
	}
	public File(String name, Directory parentDirectory) {
		this.setName(name);
		this.setParentDirectory(parentDirectory);
	}

}
