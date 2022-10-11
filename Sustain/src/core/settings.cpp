#include "settings.h"

#include <iostream>
#include <fstream>

#include <INIReader.h>

namespace Sustain {

	Settings* Settings::s_instance = nullptr;
	std::string Settings::s_renderer = "opengl";
	int Settings::s_windowWidth = 1600;
	int Settings::s_windowHeight = 900;

	Scope<Settings> Settings::Create() {
		return CreateScope<Settings>();
	}

	Settings::Settings() {
		if (s_instance != nullptr) {
			SUS_CORE_ERROR("Settings is being initialized for the second time");
			return;
		}

		s_instance = this;

		m_settingsFile = Resources::GetAppDir() / m_settingsFileName;
		if (!std::filesystem::exists(m_settingsFile)) CreateSettingsFile();
		LoadSettings();
	}

	Settings::~Settings() {

	}

	void Settings::CreateSettingsFile() {
		SUS_CORE_INFO("Settings file not found, creating new settings file.");

		std::ofstream settingsFile(m_settingsFile);

		settingsFile << "[WINDOW]\n" <<
			"windowWidth=1600\n" <<
			"windowHeight=900\n";

		settingsFile.close();
	}

	void Settings::LoadSettings() {
		INIReader reader(m_settingsFile.string());
		if (reader.ParseError() != 0) {
			SUS_CORE_ERROR("Error reading settings file");
			return;
		}

		s_windowWidth = reader.GetInteger("WINDOW", "windowWidth", 1600);
		s_windowHeight = reader.GetInteger("WINDOW", "windowHeight", 900);
	}

}
