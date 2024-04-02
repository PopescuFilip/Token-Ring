#pragma once
#include "CircularLinkedList.h"
#include "Computer.h"
#include "Token.h"
#include "Timer.h"

class TokenRingNetwork
{
public:
	TokenRingNetwork(int noOfComputers);
	
	void Print() const;

	void SimulateFor(std::chrono::seconds seconds);
private:
	Token m_token;
	CircularLinkedList<Computer> m_computers;
};

