#ifndef SUSTAIN_INPUT_H
#define SUSTAIN_INPUT_H

#include <SDL.h>

namespace Sustain {

    class Input {
    private:

    public:
        bool IsControl;
        bool IsShift;
        bool IsAlt;
    };

}

#endif // SUSTAIN_INPUT_H
