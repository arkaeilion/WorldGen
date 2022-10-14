#include "window.h"

namespace Sustain {

    Window::Window(const WindowData& data) {
        Init(data);
    }

    Window::~Window() {
        if (m_initCode != SUSTAIN_CODE::NONE)
            Shutdown();
    }

    void Window::SetVSync(bool enabled) {
        m_data.VSync = enabled;
        SDL_GL_SetSwapInterval(m_data.VSync); // Enable vsync
    }

    SUSTAIN_CODE Window::Shutdown() {
        return SUSTAIN_CODE::OK;
    }

    SUSTAIN_CODE Window::Init(const WindowData& data) {
        m_data = data;

        m_initCode = SUSTAIN_CODE::OK;
        SUS_CORE_INFO("Window finalized");
        return m_initCode;
    }

    SUSTAIN_CODE Window::UpdateLoop() {
        return SUSTAIN_CODE::OK;
    }

    void Window::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {

    }

    void Window::SetClearColor(Color& color) {
        m_data.ClearColor = color;
    }

    void Window::Clear() {

    }

}
