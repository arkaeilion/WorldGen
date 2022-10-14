#ifndef SUSTAIN_SETTINGS_H
#define SUSTAIN_SETTINGS_H

#include <string>
#include <filesystem>
#include <map>

#include "common.h"
#include "resources.h"

namespace Sustain {

    class Settings {
    public:
        Settings();
        ~Settings();

        void CreateSettingsFile();
        void LoadSettings();
    private:
        std::string m_settingsFileName = "settings.ini";
        std::filesystem::path m_settingsFile;

    public:
        static Settings& Get() { return *s_instance; }
        static Scope<Settings> Create();

        static int GetWindowWidth() { return s_windowWidth; }
        static int GetWindowHeight() { return s_windowHeight; }
    private:
        static Settings* s_instance;

        static int s_windowWidth;
        static int s_windowHeight;
    };

}

#endif // SUSTAIN_SETTINGS_H
