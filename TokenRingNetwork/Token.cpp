#include "Token.h"

namespace tokenRingNetwork
{
    Token::Token() :
        m_message{ "" },
        m_isFree{ true },
        m_reachedDestination{ false }
    {}

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

    void Token::Free()
    {
        m_isFree = true;
        m_message = "";
    }
}