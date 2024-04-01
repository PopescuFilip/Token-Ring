#pragma once
#include<string>

class Token
{
public:
	Token();

	void Send(const std::string& source, const std::string& destination);

private:
	std::string m_sourceIP;
	std::string m_destinationIP;
	bool m_isFree;
	bool m_arrived;
};

