#include "sustain.h"

namespace Sustain  {

	Sustain* Sustain::s_instance = nullptr;

	Sustain::Sustain() {
		Log::Init();

		s_instance = this;

		m_resources = Resources::Create();
		m_settings = Settings::Create();


		m_renderer = Renderer::Create();
		m_window = Window::Create();

		m_initCode = m_window->GetInitCode();
	}

	Sustain::~Sustain() {

	}

	void Sustain::Run() {
		m_runCode = m_window->UpdateLoop();
	}

}
