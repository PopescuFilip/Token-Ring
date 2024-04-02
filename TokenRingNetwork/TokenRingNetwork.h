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
	void GenerateRequest();
	void AddComputer();
	void ProcessState(Computer& current, uint16_t& sentMessages);
	
	static std::string GetDefaultMessage();

private:
	static const std::string kDefaultMessage;
	static int sMessageCounter;

private:
	Token m_token;
	CircularLinkedList<Computer> m_network;
	std::vector<Computer> m_computers;
};

