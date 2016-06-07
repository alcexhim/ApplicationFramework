/*
 * ConfigurationManager.h
 *
 *  Created on: May 7, 2016
 *      Author: beckermj
 */

#ifndef APPLICATIONFRAMEWORK_CONFIGURATION_CONFIGURATIONMANAGER_H_
#define APPLICATIONFRAMEWORK_CONFIGURATION_CONFIGURATIONMANAGER_H_

#include <Collections/Generic/List.h>
#include <IO/Directory.h>
#include <IO/File.h>
#include <String.h>

#include <Document.h>
#include <ObjectModels/Markup/MarkupObjectModel.h>
#include <DataFormats/Markup/XML/XMLDataFormat.h>
#include <Accessors/FileAccessor.h>

using ApplicationFramework::Collections::Generic::List;
using ApplicationFramework::IO::Directory;
using ApplicationFramework::IO::File;
using ApplicationFramework::String;

using UniversalEditor::Document;
using UniversalEditor::Accessors::FileAccessor;
using UniversalEditor::ObjectModels::Markup::MarkupObjectModel;
using UniversalEditor::DataFormats::Markup::XML::XMLDataFormat;

namespace ApplicationFramework {
namespace Configuration {

class ConfigurationManager {
private:
	static String* _BasePath;
	static MarkupObjectModel* _Markup;
	static List<String*>* _FileNameFilters;
public:
	ConfigurationManager();
	virtual ~ConfigurationManager();

	static void initialize();

	static String* getBasePath();
	static void setBasePath(String* path);

	static List<String*>* getFileNameFiltersList();
	static void addFileNameFilter(String* value);
	static void addFileNameFilter(const char* value);

	static MarkupObjectModel* getMarkup();
};

} /* namespace Configuration */
} /* namespace ApplicationFramework */

#endif /* APPLICATIONFRAMEWORK_CONFIGURATION_CONFIGURATIONMANAGER_H_ */
