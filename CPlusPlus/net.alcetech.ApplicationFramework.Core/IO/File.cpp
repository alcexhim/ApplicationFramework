/*
 * File.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: beckermj
 */

#include "File.h"

namespace ApplicationFramework {
namespace IO {

File::File(String* fileName, Directory* parentDirectory) {
	this->_length = -1;
	this->_exists = false;
	this->_fileName = NULL;
	this->_parentDirectory = parentDirectory;

	this->setFileName(fileName);
}
File::File(const char* fileName, Directory* parentDirectory) {
	this->_length = -1;
	this->_exists = false;
	this->_fileName = NULL;
	this->_parentDirectory = parentDirectory;

	this->setFileName(new String(fileName));
}

File::~File() {
	// TODO Auto-generated destructor stub
}

String* File::getFileName() {
	return this->_fileName;
}
void File::setFileName(String* value) {
	this->_fileName = value;

	FILE* pFile = fopen(this->getFullPath()->toCharArray(), "r");
	if (pFile != NULL)
	{
		struct stat64* _buf = new struct stat64();
		fstat64(pFile->_fileno, _buf);

		this->_length = _buf->st_size;
		this->_exists = true;

		fclose(pFile);
	}
	else
	{
		this->_exists = false;
	}
}

bool File::exists() {
	return this->_exists;
}

String* File::getFullPath() {
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

Directory* File::getParentDirectory() {
	return this->_parentDirectory;
}

} /* namespace IO */
} /* namespace ApplicationFramework */
