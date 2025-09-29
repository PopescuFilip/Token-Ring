#pragma once

#include<string>

namespace tokenRingNetwork
{
    class Token
    {
    public:
        Token();

        void Request(const std::string& source, const std::string& destination);

        std::string GetSource() const { return m_sourceIP; }
        std::string GetDestination() const { return m_destinationIP; }
        std::string GetMessage() const { return m_message; }
        bool IsFree() const { return m_isFree; }
        bool HasReachedDestination() const { return m_reachedDestination; }
        bool HasMessage() const { return m_message != ""; }

        void SetMessage(const std::string& message) { m_message = message; }
        void SetReachedDestination(bool reachedDestination) { m_reachedDestination = reachedDestination; };
        void Free();

    private:
        std::string m_sourceIP;
        std::string m_destinationIP;
        std::string m_message;
        bool m_isFree;
        bool m_reachedDestination;
    };
}