#include "TokenRingNetwork.h"

TokenRingNetwork::TokenRingNetwork(int noOfComputers)
{
	for (size_t i = 0; i < noOfComputers; i++)
		m_computers.AddNode({});
}

void TokenRingNetwork::Print() const
{
	m_computers.Print();
}

void TokenRingNetwork::SimulateFor(std::chrono::seconds seconds)
{
	auto it = m_computers.begin();

	Timer timer(seconds.count());
	timer.Start();
	while (!timer.ReachedThreshold())
	{
		std::cout << (*it).GetName() <<": moves the token\n";
		++it;
	}
}
