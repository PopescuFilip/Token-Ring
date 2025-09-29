#include "TokenRingNetwork.h"

int main()
{
    tokenRingNetwork::TokenRingNetwork network{ 15 };
    network.SendMessages(100);
    network.Print();
}