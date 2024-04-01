#include<iostream>
#include "CircularLinkedList.h"

int main()
{
	std::unique_ptr<Node<int>> node;
	
	CircularLinkedList<int> list;
	list.PrintList();
	list.AddNode(1);
	list.PrintList();
	list.AddNode(2);
	list.PrintList();
	list.AddNode(3);
	list.PrintList();
	list.AddNode(4);
	list.PrintList();
	return 0;
}