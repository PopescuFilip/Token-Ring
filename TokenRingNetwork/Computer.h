#pragma once
#include<string>

class Computer
{
public:
	Computer();

	const std::string GetIP() const;
	std::string GetBuffer() const;

	void SetBuffer(const std::string& message);
private:
	const std::string m_IPAdress;
	std::string m_buffer;
};

