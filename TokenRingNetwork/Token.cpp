#include "Token.h"

Token::Token():
	m_message{ "" },
	m_isFree{ true },
	m_reachedDestination{ false }
{
}

void Token::Request(const std::string& source, const std::string& destination)
{
	if (!m_isFree)
		return;

	m_sourceIP = source;
	m_destinationIP = destination;
	m_message = "";
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

bool Token::HasMessage() const
{
	return m_message != "";
}

void Token::SetMessage(const std::string& message)
{
	m_message = message;
}

void Token::Free()
{
	m_isFree = true;
	m_message = "";
}

void Token::SetReachedDestination(bool reachedDestination)
{
	m_reachedDestination = reachedDestination;
}
