#include "TokenRingNetwork.h"

int main()
{
	TokenRingNetwork network{ 15 };
	network.SendMessages(10);
	network.Print();
}