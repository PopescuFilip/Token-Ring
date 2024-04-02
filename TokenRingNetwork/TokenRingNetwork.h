#pragma once
#include "CircularLinkedList.h"
#include "Computer.h"
#include "Token.h"
#include <vector>

class TokenRingNetwork
{
public:
	TokenRingNetwork(int noOfComputers);
	
	void Print() const;

	void SendMessages(int noOfMessages);

private:
	int GetRandomIndex();
	void SendMessage(CircularListIterator<Computer>& it);
	void AddComputer();

private:
	Token m_token;
	CircularLinkedList<Computer> m_network;
	std::vector<Computer> m_computers;
};

