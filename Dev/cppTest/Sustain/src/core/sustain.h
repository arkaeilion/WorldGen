#ifndef SUSTAIN_SUSTAIN_H
#define SUSTAIN_SUSTAIN_H

#include "common.h"
#include "window.h"
#include "resources.h"
#include "settings.h"

namespace Sustain {

    class Sustain {
    public:
        Sustain();
        ~Sustain();

        void Run();

        Window& GetWindow() { return *m_window; }
        SUSTAIN_CODE GetInitCode() { return m_initCode; }
        SUSTAIN_CODE GetRunCode() { return m_runCode; }

    private:
        Scope<Window> m_window;
        Scope<Resources> m_resources;
        Scope<Settings> m_settings;

        SUSTAIN_CODE m_initCode;
        SUSTAIN_CODE m_runCode;

    public:
        static Sustain& Get() { return *s_instance; }

    private:
        static Sustain* s_instance;
    };

}

#endif // SUSTAIN_SUSTAIN_H
