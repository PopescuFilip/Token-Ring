#pragma once
#include<string>

class Token
{
public:
	Token();

	void Send(const std::string& source, const std::string& destination, const std::string& message);

	std::string GetSource() const;
	std::string GetDestination() const;
	std::string GetMessage() const;
	bool IsFree() const;
	bool HasReachedDestination() const;

	void SetIsFree(bool isFree);
	void SetReachedDestination(bool reachedDestination);

private:
	std::string m_sourceIP;
	std::string m_destinationIP;
	std::string m_message;
	bool m_isFree;
	bool m_reachedDestination;
};

