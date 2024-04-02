#include "Timer.h"

Timer::Timer(const uint16_t& duration) :
	m_duration{ duration },
	m_isActive{ false }
{
}

uint16_t Timer::GetDuration() const
{
	return m_duration;
}

uint16_t Timer::GetElapsedTime() const
{
	auto currentTime{ high_resolution_clock::now() };
	auto duration = duration_cast<seconds>(currentTime - m_startTime).count();
	return duration;
}

bool Timer::ReachedThreshold() const
{
	return GetElapsedTime() >= m_duration;
}

void Timer::Start()
{
	m_startTime = high_resolution_clock::now();
	m_isActive = true;
}

void Timer::Stop()
{
	m_isActive = false;
}

bool Timer::IsActive() const
{
	return m_isActive;
}
