package net.alcetech.ApplicationFramework.IO;

import java.util.ArrayList;

import net.alcetech.ApplicationFramework.Wildcard;

public class Directory extends FileSystemObject {
	
	public Directory(String fullPath) {
		this.setFullPath(fullPath);
	}
	public Directory(String name, Directory parentDirectory) {
		this.setName(name);
		this.setParentDirectory(parentDirectory);
	}

	
	public Directory[] getDirectories() {
		return getDirectories("*");
	}
	public Directory[] getDirectories(String pattern) {
		return getDirectories(pattern, false);
	}
	public Directory[] getDirectories(String pattern, boolean searchChildDirectories) {
		ArrayList<Directory> list = new ArrayList<Directory>();
		FileSystemObject[] objects = getObjects(pattern, searchChildDirectories, true, false);
		for (int i = 0; i < objects.length; i++) {
			list.add((Directory)objects[i]);
		}
		
		Directory[] array = new Directory[list.size()];
		list.toArray(array);
		return array;
	}
	
	public File[] getFiles() {
		return getFiles("*");
	}
	public File[] getFiles(String pattern) {
		return getFiles(pattern, false);
	}
	public File[] getFiles(String pattern, boolean searchChildDirectories) {
		ArrayList<File> list = new ArrayList<File>();
		FileSystemObject[] objects = getObjects(pattern, searchChildDirectories, false, true);
		for (int i = 0; i < objects.length; i++) {
			list.add((File)objects[i]);
		}
		
		File[] array = new File[list.size()];
		list.toArray(array);
		return array;
	}
	
	public FileSystemObject[] getObjects() {
		return getObjects("*");
	}
	public FileSystemObject[] getObjects(String pattern) {
		return getObjects(pattern, false);
	}
	public FileSystemObject[] getObjects(String pattern, boolean searchChildDirectories) {
		return getObjects(pattern, searchChildDirectories, true, true);
	}
	public FileSystemObject[] getObjects(String pattern, boolean searchChildDirectories, boolean includeDirectories, boolean includeFiles) {
		ArrayList<FileSystemObject> list = new ArrayList<FileSystemObject>();
		
		java.io.File jioFile = this.getUnderlyingFile();
		
		java.io.File[] files = jioFile.listFiles();
		if (files == null) return new FileSystemObject[0];
		
		for (int i = 0; i < files.length; i++) {
			if (files[i].isDirectory() && (includeDirectories || searchChildDirectories)) {
				Directory directory = new Directory(files[i].getName(), this);
				if (includeDirectories) {
					if (Wildcard.matches(files[i].getName(), pattern)) list.add(directory);
				}
				
				if (searchChildDirectories) {
					FileSystemObject[] childObjects = directory.getObjects(pattern, searchChildDirectories, includeDirectories, includeFiles);
					for (int j = 0; j < childObjects.length; j++) {
						list.add(childObjects[j]);
					}
				}
			}
			else if (files[i].isFile() && includeFiles) {
				if (Wildcard.matches(files[i].getName(), pattern)) {
					File file = new File(files[i].getName(), this);
					list.add(file);
				}
			}
		}

		FileSystemObject[] array = new FileSystemObject[list.size()];
		list.toArray(array);
		return array;
	}

}
