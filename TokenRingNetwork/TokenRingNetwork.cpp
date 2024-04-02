#include "TokenRingNetwork.h"
#include "Random.h"

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

	auto it = m_network.begin();
	uint16_t sentMessages = 0;
	
	while (sentMessages < noOfMessages)
	{
		auto& currentComputer = (*it);
		if (m_token.IsFree())
		{
			m_network.Print();
			GenerateMessage();
		}

		ProcessState(currentComputer, sentMessages);

		if(!m_token.IsFree())
			std::cout << currentComputer.GetName() << ": moves the token\n";

		++it;
	}
}

int TokenRingNetwork::GetRandomIndex()
{
	return GetRandom(0, m_computers.size() - 1);
}

void TokenRingNetwork::GenerateMessage()
{
	int sourceIndex{ GetRandomIndex() };
	int destinationIndex{ GetRandomIndex() };
	
	while (destinationIndex == sourceIndex)
		destinationIndex = GetRandomIndex();

	Computer source{ m_computers[sourceIndex] };
	Computer destination{ m_computers[destinationIndex] };

	std::cout << "Source: " << source.GetName() << " Destination: " << destination.GetName() << '\n';
	
	std::string message{ "Test" };
	//std::cout << "Enter message: ";
	//std::cin >> message;

	m_token.Send(source.GetAdress(), destination.GetAdress(), message);
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
			return;
		}
		
		std::cout << current.GetName() << ": token has arrived back at source\n";
		m_token.SetIsFree(true);
		sentMessages++;
		return;
	}

	std::cout << current.GetName() << ": token has arrived at destination\n";
	current.SetBuffer(std::move(m_token.GetMessage()));
	m_token.SetReachedDestination(true);
}
