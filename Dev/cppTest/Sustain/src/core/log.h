#ifndef SUSTAIN_LOG_H
#define SUSTAIN_LOG_H

#include <spdlog/spdlog.h>
#include "support.h"

namespace Sustain {

    class Log {
    public:
        static void Init();

        static Ref<spdlog::logger>& GetCoreLogger() { return m_coreLogger; }
        static Ref<spdlog::logger>& GetClientLogger() { return m_clientLogger; }
    private:
        static Ref<spdlog::logger> m_coreLogger;
        static Ref<spdlog::logger> m_clientLogger;
    };

}

// Core log macros
#define SUS_CORE_TRACE(...)    ::Sustain::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SUS_CORE_INFO(...)     ::Sustain::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SUS_CORE_WARN(...)     ::Sustain::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SUS_CORE_ERROR(...)    ::Sustain::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SUS_CORE_CRITICAL(...) ::Sustain::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SUS_TRACE(...)         ::Sustain::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SUS_INFO(...)          ::Sustain::Log::GetClientLogger()->info(__VA_ARGS__)
#define SUS_WARN(...)          ::Sustain::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SUS_ERROR(...)         ::Sustain::Log::GetClientLogger()->error(__VA_ARGS__)
#define SUS_CRITICAL(...)      ::Sustain::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif // SUSTAIN_LOG_H
