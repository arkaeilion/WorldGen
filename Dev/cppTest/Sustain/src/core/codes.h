#ifndef SUSTAIN_CODES_H
#define SUSTAIN_CODES_H

namespace Sustain {

    enum SUSTAIN_CODE {
        OK = 000,
        FAIL = 001,
        NONE = 003,

        SDL2_INITIALIZE_ERROR = 010,
        SDL2_WINDOW_ERROR = 011,
        SDL2_SURFACE_ERROR = 012,
        GLAD_ERROR = 013,
        IMGUI_ERROR = 014,
    };
}

#endif // SUSTAIN_CODES_H
