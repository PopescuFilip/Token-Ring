#include "TokenRingNetwork.h"

#include "Random.h"

namespace tokenRingNetwork
{
    TokenRingNetwork::TokenRingNetwork(uint16_t noOfComputers)
    {
        for (size_t i = 0; i < noOfComputers; i++)
            AddComputer();
    }

    void TokenRingNetwork::Print() const
    {
        m_network.Print();
    }

    void TokenRingNetwork::SendMessages(uint16_t noOfMessages)
    {
        if (noOfMessages <= 0)
            return;

        CircularListIterator it{ std::move(m_network.begin()) };
        uint16_t sentMessages = 0;

        while (sentMessages < noOfMessages)
        {
            Computer& currentComputer = (*it);
            if (m_token.IsFree())
            {
                m_network.Print();
                GenerateRequest();
            }

            ProcessState(currentComputer, sentMessages);

            if (!m_token.IsFree())
                std::cout << currentComputer.GetName() << ": moves the token\n";

            ++it;
        }
    }

    size_t TokenRingNetwork::GetRandomIndex() const
    {
        return GetRandom(0, m_computers.size() - 1);
    }

    void TokenRingNetwork::GenerateRequest()
    {
        size_t sourceIndex{ GetRandomIndex() };
        size_t destinationIndex{ GetRandomIndex() };

        while (destinationIndex == sourceIndex)
            destinationIndex = GetRandomIndex();

        const Computer& source = m_computers[sourceIndex];
        const Computer& destination = m_computers[destinationIndex];

        std::cout << "Source: " << source.GetName() << " Destination: " << destination.GetName() << '\n';
        m_token.Request(source.GetAdress(), destination.GetAdress());
    }

    void TokenRingNetwork::AddComputer()
    {
        Computer c;
        m_computers.emplace_back(c);
        m_network.AddNode(std::move(c));
    }

    void TokenRingNetwork::ProcessState(Computer& current, uint16_t& sentMessages)
    {
        if (m_token.GetSource() != current.GetAdress() and m_token.GetDestination() != current.GetAdress())
            return;

        if (m_token.GetSource() == current.GetAdress())
        {
            if (!m_token.HasReachedDestination())
            {
                std::cout << current.GetName() << ": has received the token\n";
                m_token.SetMessage(std::move(TokenRingNetwork::GetDefaultMessage()));
                return;
            }

            std::cout << current.GetName() << ": token has arrived back at source\n\n";
            m_token.Free();
            sentMessages++;
            return;
        }

        if (!m_token.HasMessage())
            return;

        std::cout << current.GetName() << ": token has arrived at destination\n";
        current.AddToBuffer(std::move(m_token.GetMessage()));
        m_token.SetReachedDestination(true);
    }

    std::string TokenRingNetwork::GetDefaultMessage()
    {
        return kBaseMessage + std::to_string(sMessageCounter++);
    }
}