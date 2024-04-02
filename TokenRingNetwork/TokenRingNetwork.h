#pragma once
#include "CircularLinkedList.h"
#include "Computer.h"
#include "Token.h"
#include <vector>

class TokenRingNetwork
{
public:
	TokenRingNetwork(uint16_t noOfComputers);
	
	void Print() const;

	void SendMessages(uint16_t noOfMessages);

private:
	int GetRandomIndex();
	void GenerateMessage();
	void AddComputer();
	void ProcessState(Computer& current, uint16_t& sentMessages);

private:
	Token m_token;
	CircularLinkedList<Computer> m_network;
	std::vector<Computer> m_computers;
};

