#ifndef SUSTAIN_ENTRY_POINT_H
#define SUSTAIN_ENTRY_POINT_H

#include "application.h"

extern Sustain::Application* Sustain::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv) {

    Sustain::Log::Init();

    auto app = Sustain::CreateApplication({ argc, argv });

    app->Run();

    delete app;

    return 0;
}

#endif // SUSTAIN_ENTRY_POINT_H
