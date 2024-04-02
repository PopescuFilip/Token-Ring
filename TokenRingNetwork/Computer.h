#pragma once
#include<string>

class Computer
{
public:

	Computer();

	const std::string GetAdress() const;
	std::string GetBuffer() const;
	std::string GetName() const;

	void SetBuffer(const std::string& message);


private:

	const int kNumber;
	const std::string kIPAdress;

	static int sCounter;

private:

	std::string m_buffer;

};
std::ostream& operator<<(std::ostream& os, const Computer& c);

