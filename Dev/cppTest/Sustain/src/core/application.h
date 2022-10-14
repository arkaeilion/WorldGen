#ifndef SUSTAIN_APPLICATION_H
#define SUSTAIN_APPLICATION_H

#include "common.h"
#include "window.h"
#include "resources.h"
#include "settings.h"

int main(int argc, char** argv);

namespace Sustain {

    struct ApplicationCommandLineArgs {
        int Count = 0;
        char** Args = nullptr;

        const char* operator[](int index) const {
            // HZ_CORE_ASSERT(index < Count);
            return Args[index];
        }
    };

    struct ApplicationSpecification {
        std::string Name = "Sustain Application";
        std::string WorkingDirectory;
        ApplicationCommandLineArgs CommandLineArgs;
    };

    class Application {
    public:
        Application(const ApplicationSpecification& specification);
        virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

        void Close();

        Window& GetWindow() { return *m_window; }
        ImGuiLayer* GetImGuiLayer() { return m_imGuiLayer; }
		const ApplicationSpecification& GetSpecification() const { return m_specification; }
        static Application& Get() { return *s_instance; }

        SUSTAIN_CODE GetErrorCode() { return m_errorCode; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

        Scope<Window> m_window;
        Scope<Resources> m_resources;
        Scope<Settings> m_settings;
        ApplicationSpecification m_specification;
        ImGuiLayer* m_imGuiLayer;
		bool m_running = true;
		bool m_minimized = false;
		LayerStack m_layerStack;
		float m_lastFrameTime = 0.0f;
        SUSTAIN_CODE m_errorCode;

        static Application* s_instance;
        friend int ::main(int argc, char** argv);
    };

    // To be defined in CLIENT
    Application* CreateApplication(ApplicationCommandLineArgs args);

}

#endif // SUSTAIN_APPLICATION_H
