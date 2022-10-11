#ifndef SUSTAIN_RESOURCES_H
#define SUSTAIN_RESOURCES_H

#include <string>
#include <windows.h>
#include <filesystem>

#include "common.h"

namespace Sustain {

	class Resources {
	public:
		Resources();
		~Resources();

		static Resources& Get() { return *s_instance; }

		static std::filesystem::path& GetResourcesDir() { return *s_resourcesDir; };
		static std::filesystem::path& GetAppDir() { return *s_appDir; };
		static std::filesystem::path& GetAppPath() { return *s_appPath; };

		static Scope<Resources> Create();

	private:
		static Resources* s_instance;
		static std::filesystem::path* s_resourcesDir;
		static std::filesystem::path* s_appDir;
		static std::filesystem::path* s_appPath;
	};

}

#endif // SUSTAIN_RESOURCES_H
