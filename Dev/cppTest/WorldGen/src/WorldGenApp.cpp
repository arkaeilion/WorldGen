#include <sustain.h>

namespace Sustain {

    class WorldGenApp : public Application {
    public:
        WorldGenApp(const ApplicationSpecification& spec)
            : Application(spec) {
            PushLayer(new EditorLayer());
        }
    };

    Application* CreateApplication(ApplicationCommandLineArgs args) {
        ApplicationSpecification spec;
        spec.Name = "WorldGen";
        spec.CommandLineArgs = args;

        return new WorldGenApp(spec);
    }

}
