#include<iostream>
#include "CircularLinkedList.h"
#include "Computer.h"

#include<thread>

int main()
{

	std::unique_ptr<Node<int>> node;

	CircularLinkedList<Computer> list;
	list.AddNode({});
	list.AddNode({});
	list.AddNode({});
	list.AddNode({});
	auto it = list.begin();
	while (true)
	{
		std::cout << (*it).GetName() << '\n';
		++it;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return 0;
}