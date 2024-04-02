#include<iostream>
#include "TokenRingNetwork.h"

#include<thread>

int main()
{
	TokenRingNetwork network(5);
	network.SimulateFor(std::chrono::seconds(2));
	return 0;
}