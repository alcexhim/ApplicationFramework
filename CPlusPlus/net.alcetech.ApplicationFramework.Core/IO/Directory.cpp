/*
 * Directory.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: beckermj
 */

#include "Directory.h"

namespace ApplicationFramework {
namespace IO {

Directory::Directory(String* fileName, Directory* parentDirectory) {
	this->_fileName = fileName;
	this->_parentDirectory = parentDirectory;
}

Directory::~Directory() {
	// TODO Auto-generated destructor stub
}

List<Directory*>* Directory::getDirectories() {
	return this->getDirectories(new String("*"));
}
List<Directory*>* Directory::getDirectories(String* pattern) {
	return this->getDirectories(pattern, 1);
}
List<Directory*>* Directory::getDirectories(String* pattern, int levels) {
	List<Directory*>* list = new List<Directory*>();
	Directory::getDirectoriesInternal(list, pattern, levels, this, 0);
	return list;
}
List<File*>* Directory::getFiles() {
	return this->getFiles(new String("*"));
}
List<File*>* Directory::getFiles(String* pattern) {
	return this->getFiles(pattern, 1);
}
List<File*>* Directory::getFiles(String* pattern, int levels) {
	List<File*>* list = new List<File*>();
	Directory::getFilesInternal(list, pattern, levels, this, 0);
	return list;
}

String* Directory::getFileName() {
	return this->_fileName;
}
void Directory::setFileName(String* value) {
	this->_fileName = value;
}

void Directory::getDirectoriesInternal(List<Directory*>* list, String* pattern, int levels, Directory* parentDirectory, int currentLevel) {
	DIR* dirhandle = opendir(parentDirectory->getFileName()->toCharArray());
	struct dirent64* dirent = NULL;

	while ((dirent = readdir64(dirhandle)) != NULL)
	{
		if (dirent->d_type != DT_DIR) continue;

		String* name = new String(dirent->d_name);
		if (name->equals(".") || name->equals("..")) continue;

		Directory* dir = new Directory(name);
		list->add(dir);

		if (levels == -1 || currentLevel < levels) {
			Directory::getDirectoriesInternal(list, pattern, levels, dir, currentLevel + 1);
		}
	}
}
void Directory::getFilesInternal(List<File*>* list, String* pattern, int levels, Directory* parentDirectory, int currentLevel) {
	DIR* dirhandle = opendir(parentDirectory->getFullPath()->toCharArray());
	struct dirent64* dirent = NULL;

	while ((dirent = readdir64(dirhandle)) != NULL)
	{
		if (dirent->d_type == DT_REG)
		{
			StringBuilder* sbName = new StringBuilder();
			String* name = new String(dirent->d_name);
			if (name->equals(".") || name->equals("..")) continue;
			if (!name->matches(pattern)) continue;

			sbName->append(name);

			File* file = new File(sbName->toString(), parentDirectory);
			list->add(file);
		}
		else if (dirent->d_type == DT_DIR)
		{
			String* name = new String(dirent->d_name);
			if (name->equals(".") || name->equals("..")) continue;

			Directory* dir = new Directory(name, parentDirectory);
			if (levels == -1 || currentLevel < levels) {
				Directory::getFilesInternal(list, pattern, levels, dir, currentLevel + 1);
			}
		}
	}
}

String* Directory::getFullPath() {
	StringBuilder* sb = new StringBuilder();
	Directory* parent = this->getParentDirectory();
	if (parent != NULL)
	{
		sb->append(parent->getFullPath());
		sb->append("/");
	}
	sb->append(this->getFileName());
	return sb->toString();
}

Directory* Directory::getParentDirectory() {
	return this->_parentDirectory;
}

} /* namespace IO */
} /* namespace ApplicationFramework */
