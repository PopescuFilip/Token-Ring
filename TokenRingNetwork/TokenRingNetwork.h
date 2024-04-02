#pragma once
#include "CircularLinkedList.h"
#include "Computer.h"
#include "Token.h"

class TokenRingNetwork
{
public:
	TokenRingNetwork(int noOfComputers);
	
private:
	Token m_token;
	CircularLinkedList<Computer> m_computers;
};

