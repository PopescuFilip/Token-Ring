#include "TokenRingNetwork.h"
#include "Random.h"

TokenRingNetwork::TokenRingNetwork(int noOfComputers)
{
	for (size_t i = 0; i < noOfComputers; i++)
		AddComputer();
}

void TokenRingNetwork::Print() const
{
	m_network.Print();
}

void TokenRingNetwork::SendMessages(int noOfMessages)
{
	auto it = m_network.begin();
	m_network.Print();
	for (size_t i = 0; i < noOfMessages; i++)
	{
		SendMessage(it);

		std::cout << (*it).GetName() << ": moves the token\n";
		++it;
	}
}

int TokenRingNetwork::GetRandomIndex()
{
	return GetRandom(0, m_computers.size() - 1);
}

void TokenRingNetwork::SendMessage(CircularListIterator<Computer>& it)
{
	int sourceIndex{ GetRandomIndex() };
	int destinationIndex{ GetRandomIndex() };
	while (destinationIndex == sourceIndex)
		destinationIndex = GetRandomIndex();

	std::cout << "Source: " << m_computers[sourceIndex].GetName() << " Destination: " << m_computers[destinationIndex].GetName() << '\n';
}

void TokenRingNetwork::AddComputer()
{
	Computer c;
	m_computers.emplace_back(c);
	m_network.AddNode(std::move(c));
}
