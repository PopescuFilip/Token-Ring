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
