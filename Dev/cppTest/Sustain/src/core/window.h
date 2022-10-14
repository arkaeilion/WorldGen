#ifndef SUSTAIN_WINDOW_H
#define SUSTAIN_WINDOW_H

#include "common.h"
#include "color.h"

#include <SDL.h>
#include <vulkan/vulkan.h>

// virtual type func() const = 0; code inside this function will not modify the containing object.
// virtual type func() = 0; function is pure virtual, means it must be overridden by a sub-class.

namespace Sustain {

    struct WindowData {
        std::string Title;
        uint32_t Width;
        uint32_t Height;
        Color ClearColor;
        bool VSync;

        WindowData(const std::string& title = "Sustain",
            uint32_t width = 1600,
            uint32_t height = 900,
            Color clearColor = Color::Cyan(),
            bool vSync = false) :
            Title(title), Width(width), Height(height),
            ClearColor(clearColor), VSync(vSync) {}
    };

    class Window {
    private:
        WindowData m_data;
        SUSTAIN_CODE m_initCode = SUSTAIN_CODE::NONE;

        SDL_Window* m_window;
        SDL_WindowFlags m_windowFlags;

    public:
        Window(const WindowData& data = WindowData());
        ~Window();

        SUSTAIN_CODE Init(const WindowData& data = WindowData());
        SUSTAIN_CODE Shutdown();
        SUSTAIN_CODE UpdateLoop();

        void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
        void SetClearColor(Color& color);
        Color GetClearColor() { return m_data.ClearColor; }
        void Clear();

        uint32_t GetWidth() { return m_data.Width; }
        uint32_t GetHeight() { return m_data.Height; }
        std::string GetTitle() { return m_data.Title; }
        const char* GetTitleC() { return m_data.Title.c_str(); }

        void SetVSync(bool enabled);
        bool IsVSync() { return m_data.VSync; }

        SUSTAIN_CODE GetInitCode() { return m_initCode; }
    };

}

#endif // SUSTAIN_WINDOW_H
