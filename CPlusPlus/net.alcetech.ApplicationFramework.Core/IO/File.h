/*
 * File.h
 *
 *  Created on: Apr 14, 2016
 *      Author: beckermj
 */

#ifndef IO_FILE_H_
#define IO_FILE_H_

#include "Directory.h"
#include "../String.h"
#include <sys/stat.h>

using ApplicationFramework::String;

namespace ApplicationFramework {
namespace IO {

class Directory;

class File {
private:
	String* _fileName;

	bool _exists;
	unsigned long int _length;

	Directory* _parentDirectory;
public:
	File(const char* fileName, Directory* parentDirectory = NULL);
	File(String* fileName, Directory* parentDirectory = NULL);

	virtual ~File();

	String* getFileName();
	void setFileName(String* value);

	bool exists();

	String* getFullPath();
	Directory* getParentDirectory();
};

} /* namespace IO */
} /* namespace ApplicationFramework */

#endif /* IO_FILE_H_ */
