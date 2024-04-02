#pragma once
#include "CircularLinkedList.h"
#include "Computer.h"
#include "Token.h"

class TokenRingNetwork
{
public:
	TokenRingNetwork(int noOfComputers);
	
	void Print() const;
private:
	Token m_token;
	CircularLinkedList<Computer> m_computers;
};

