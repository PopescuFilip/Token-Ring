#include "TokenRingNetwork.h"
#include "Random.h"

int TokenRingNetwork::sMessageCounter = 0;
const std::string TokenRingNetwork::kDefaultMessage = "message";

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
			GenerateRequest();
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

void TokenRingNetwork::GenerateRequest()
{
	int sourceIndex{ GetRandomIndex() };
	int destinationIndex{ GetRandomIndex() };
	
	while (destinationIndex == sourceIndex)
		destinationIndex = GetRandomIndex();

	Computer source{ m_computers[sourceIndex] };
	Computer destination{ m_computers[destinationIndex] };

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
	current.SetBuffer(std::move(m_token.GetMessage()));
	m_token.SetReachedDestination(true);
}

std::string TokenRingNetwork::GetDefaultMessage()
{
	sMessageCounter++;
	return kDefaultMessage + '_' + std::to_string(sMessageCounter);
}
