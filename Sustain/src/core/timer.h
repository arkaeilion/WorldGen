#ifndef SUSTAIN_TIMER_H
#define SUSTAIN_TIMER_H

#include <chrono>

namespace Sustain {

	class Timer {
	public:
		Timer() {
			Reset();
		}

		void Timer::Reset() {
			m_start = std::chrono::high_resolution_clock::now();
		}

		float Timer::Elapsed() {
			return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_start).count() * 0.001f * 0.001f * 0.001f;
		}

		float Timer::ElapsedMillis() {
			return Elapsed() * 1000.0f;
		}

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
	};

	class Time {
	public:
		static uint64_t GetTime() {
			using namespace std::chrono;
			milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
			return ms.count();
		};
	};

}

#endif // SUSTAIN_TIMER_H
