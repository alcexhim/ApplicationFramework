/*
 * ConfigurationManager.cpp
 *
 *  Created on: May 7, 2016
 *      Author: beckermj
 */

#include "ConfigurationManager.h"

namespace ApplicationFramework {
namespace Configuration {

String* ConfigurationManager::_BasePath = String::EMPTY;
MarkupObjectModel* ConfigurationManager::_Markup = new MarkupObjectModel();
List<String*>* ConfigurationManager::_FileNameFilters = new List<String*>();

ConfigurationManager::ConfigurationManager() {
	// TODO Auto-generated constructor stub

}

ConfigurationManager::~ConfigurationManager() {
	// TODO Auto-generated destructor stub
}

String* ConfigurationManager::getBasePath() {
	return ConfigurationManager::_BasePath;
}
void ConfigurationManager::setBasePath(String* value) {
	ConfigurationManager::_BasePath = value;
}

List<String*>* ConfigurationManager::getFileNameFiltersList() {
	return ConfigurationManager::_FileNameFilters;
}
void ConfigurationManager::addFileNameFilter(String* value) {
	ConfigurationManager::_FileNameFilters->add(value);
}
void ConfigurationManager::addFileNameFilter(const char* value) {
	ConfigurationManager::addFileNameFilter(new String(value));
}

void ConfigurationManager::initialize() {

	XMLDataFormat* xdf = new XMLDataFormat();

	Directory* baseDir = new Directory(ConfigurationManager::getBasePath());

	List<String*>* fileNameFilters = ConfigurationManager::getFileNameFiltersList();
	for (int i = 0; i < fileNameFilters->count(); i++) {
		String* fileNameFilter = fileNameFilters->get(i);

		List<File*>* files = baseDir->getFiles(fileNameFilter, -1);
		for (int j = 0; j < files->count(); j++) {

			File* file = files->get(j);
			FileAccessor* fa = FileAccessor::fromFileName(file->getFullPath()->toCharArray());

			printf("appfx-config: loading file %d of %d: '%s'\n\n", j + 1, files->count(), file->getFullPath()->toCharArray());
			Document::load(ConfigurationManager::_Markup, xdf, fa);
			printf("\n");
		}

	}
}

MarkupObjectModel* ConfigurationManager::getMarkup() {
	return ConfigurationManager::_Markup;
}

} /* namespace Configuration */
} /* namespace ApplicationFramework */
