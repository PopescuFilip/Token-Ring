#include<iostream>
#include "LinkedList.h"

int main()
{
	Node<int> node{ 1 };
	std::cout << node.m_value;
	LinkedList<int> list(5);
	return 0;
}