#pragma once
#include<string>

class Token
{
public:
	Token();

	void Send(const std::string& source, const std::string& destination);

	std::string GetSource() const;
	std::string GetDestination() const;
	bool IsFree() const;
	bool HasReachedDestination() const;

	void SetIsFree(bool isFree);
	void SetReachedDestination(bool reachedDestination);

private:
	std::string m_sourceIP;
	std::string m_destinationIP;
	bool m_isFree;
	bool m_reachedDestination;
};

