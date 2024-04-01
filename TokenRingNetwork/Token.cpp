#include "Token.h"

Token::Token():
	m_isFree{ true },
	m_arrived{ false }
{
}

void Token::Send(const std::string& source, const std::string& destination)
{
	if (!m_isFree)
		return;

	m_sourceIP = source;
	m_destinationIP = destination;
	m_isFree = false;
	m_arrived = false;
}
