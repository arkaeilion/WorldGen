#ifndef SUSTAIN_COLOR_H
#define SUSTAIN_COLOR_H

namespace Sustain {

    struct Color {

        // https://stackoverflow.com/questions/44124022/add-predefined-colors-to-a-simple-c-color-class

        static constexpr Color White() { return Color(1, 1, 1, 1); }
        static constexpr Color Black() { return Color(0, 0, 0, 1); }

        static constexpr Color Red() { return Color(1, 0, 0, 1); }
        static constexpr Color Green() { return Color(0, 1, 0, 1); }
        static constexpr Color Blue() { return Color(0, 0, 1, 1); }

        static constexpr Color Cyan() { return Color(0.16f, 0.85f, 0.75f, 1); }

        static constexpr Color Gray() { return Color(.5f, .5f, .5f, 1); }
        static constexpr Color LightGray() { return Color(.25f, .25f, .25f, 1); }
        static constexpr Color DarkGray() { return Color(.75f, .75f, .75f, 1); }

        static constexpr Color Purple() { return Color(.618f, .247f, .682f, 1); }
        static constexpr Color LightPurple() { return Color(.337f, .113f, .368f, 1); }
        static constexpr Color RoyalPurple() { return Color(.788f, .627f, .862f, 1); }

        static constexpr Color Pink() { return Color(.929f, .678f, .701f, 1); }
        static constexpr Color BrinkPink() { return Color(.984f, .392f, .509f, 1); }
        static constexpr Color SuperLightPink() { return Color(1, .8f, .823f, 1); }
        static constexpr Color UltraPink() { return Color(.964f, .180f, .474f, 1); }

        float r;
        float g;
        float b;
        float a;

        Color() {
            r, g, b, a = 1;
        }

        // 0 - 255
        constexpr Color(float r, float g, float b, float a = 1) :
            r(r), g(g), b(b), a(a) {}

        void Set(float _r, float _g, float _b, float _a = 1) {
            r = _r; g = _g; b = _b; a = _a;
        };

        void Seti(int _r, int _g, int _b, int _a = 255) {
            r = _r / 255; g = _g / 255; b = _b / 255; a = _a / 255;
        };

    };

}

#endif // SUSTAIN_COLOR_H
