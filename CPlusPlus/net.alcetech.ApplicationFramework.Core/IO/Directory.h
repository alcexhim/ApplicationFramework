/*
 * Directory.h
 *
 *  Created on: Apr 14, 2016
 *      Author: beckermj
 */

#ifndef IO_DIRECTORY_H_
#define IO_DIRECTORY_H_

#include "File.h"

#include "../Collections/Generic/List.h"
#include "../String.h"

#include "../Text/StringBuilder.h"

#include <dirent.h>

using ApplicationFramework::Collections::Generic::List;
using ApplicationFramework::String;
using ApplicationFramework::Text::StringBuilder;

namespace ApplicationFramework {
namespace IO {

class File;

class Directory {
private:
	Directory* _parentDirectory;
	String* _fileName;

	static void getDirectoriesInternal(List<Directory*>* list, String* pattern, int levels, Directory* parentDirectory, int currentLevel);
	static void getFilesInternal(List<File*>* list, String* pattern, int levels, Directory* parentDirectory, int currentLevel);
public:
	Directory(String* fileName, Directory* parentDirectory = NULL);
	virtual ~Directory();

	/**
	 * Retrieves information about directories that are first-level children of this Directory.
	 */
	List<Directory*>* getDirectories();
	/**
	 * Retrieves information about directories that are first-level children of this Directory whose names match the specified pattern.
	 */
	List<Directory*>* getDirectories(String* pattern);
	/**
	 * Recursively (up to 'levels' levels) retrieves information about directories that are children of this Directory whose names match the specified pattern.
	 */
	List<Directory*>* getDirectories(String* pattern, int levels);
	/**
	 * Retrieves information about files that are first-level children of this Directory.
	 */
	List<File*>* getFiles();
	/**
	 * Retrieves information about files that are first-level children of this Directory whose names match the specified pattern.
	 */
	List<File*>* getFiles(String* pattern);
	/**
	 * Recursively (up to 'levels' levels) retrieves information about files that are children of this Directory whose names match the specified pattern.
	 */
	List<File*>* getFiles(String* pattern, int levels);

	String* getFileName();
	void setFileName(String* value);

	String* getFullPath();

	Directory* getParentDirectory();
};

} /* namespace IO */
} /* namespace ApplicationFramework */

#endif /* IO_DIRECTORY_H_ */
