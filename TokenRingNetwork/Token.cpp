#include "Token.h"

Token::Token():
	m_isFree{ true },
	m_reachedDestination{ false }
{
}

void Token::Send(const std::string& source, const std::string& destination, const std::string& message)
{
	if (!m_isFree)
		return;

	m_sourceIP = source;
	m_destinationIP = destination;
	m_message = message;
	m_isFree = false;
	m_reachedDestination = false;
}

std::string Token::GetSource() const
{
	return m_sourceIP;
}

std::string Token::GetDestination() const
{
	return m_destinationIP;
}

std::string Token::GetMessage() const
{
	return m_message;
}

bool Token::IsFree() const
{
	return m_isFree;
}

bool Token::HasReachedDestination() const
{
	return m_reachedDestination;
}

void Token::SetIsFree(bool isFree)
{
	m_isFree = isFree;
}

void Token::SetReachedDestination(bool reachedDestination)
{
	m_reachedDestination = reachedDestination;
}
