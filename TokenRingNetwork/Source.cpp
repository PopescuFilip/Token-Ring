#include "TokenRingNetwork.h"

int main()
{
	TokenRingNetwork network{ 10 };
	network.SendMessages(10);
	network.Print();
}