#include "resources.h"


namespace Sustain {

	Resources* Resources::s_instance = nullptr;
	std::filesystem::path* Resources::s_resourcesDir = nullptr;
	std::filesystem::path* Resources::s_appDir = nullptr;
	std::filesystem::path* Resources::s_appPath = nullptr;

	Scope<Resources> Resources::Create() {
		return CreateScope<Resources>();
	}

	Resources::Resources() {
		if ( s_instance != nullptr ) {
			SUS_CORE_ERROR("Resources is being initialized for the second time");
			return;
		}

		s_instance = this;

		char result[MAX_PATH];
		auto exePath = std::string(result, GetModuleFileName(NULL, result, MAX_PATH));

		s_appPath = new std::filesystem::path(exePath);

		std::filesystem::path tmp = std::filesystem::path(exePath);
		s_appDir = new std::filesystem::path( tmp.remove_filename() );

		std::filesystem::path resourceAppend = "Resources/";
		std::filesystem::path resourcesDir = GetAppDir() / resourceAppend;
		s_resourcesDir = new std::filesystem::path(resourcesDir);

		// SUS_CORE_INFO("s_appDir {0}", GetAppDir().string());
		// SUS_CORE_INFO("s_appPath {0}", GetAppPath().string());
		// SUS_CORE_INFO("s_resourcesDir {0}", GetResourcesDir().string());

		// for (const auto & entry : std::filesystem::recursive_directory_iterator(GetResourcesDir()))
		// 	SUS_CORE_INFO(entry.path().string());
	}

	Resources::~Resources() {
		delete s_appPath;
		delete s_appDir;
		delete s_resourcesDir;
	}

}
