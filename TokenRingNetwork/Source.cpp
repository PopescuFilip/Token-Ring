#include<iostream>
#include "CircularLinkedList.h"
#include "Computer.h"

int main()
{

	std::unique_ptr<Node<int>> node;

	CircularLinkedList<Computer> list;
	list.Print();
	list.AddNode({});
	list.Print();
	list.AddNode({});
	list.Print();
	list.AddNode({});
	list.Print();
	list.AddNode({});
	list.Print();
	return 0;
}