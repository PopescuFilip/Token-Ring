#include<iostream>
#include "CircularLinkedList.h"
#include "Computer.h"

int main()
{
	Computer c;

	std::unique_ptr<Node<int>> node;
	
	CircularLinkedList<int> list;
	list.Print();
	list.AddNode(1);
	list.Print();
	list.AddNode(2);
	list.Print();
	list.AddNode(3);
	list.Print();
	list.AddNode(4);
	list.Print();
	return 0;
}