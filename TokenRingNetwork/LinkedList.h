#pragma once
#include "Node.h"

template <typename T>
class LinkedList
{
public:
	LinkedList(int noOfNodes);

	void PushBack(T value);
private:
	Node<T>* m_head;
};

template <typename T>
inline LinkedList<T>::LinkedList(int noOfNodes)
{

}

template<typename T>
inline void LinkedList<T>::PushBack(T value)
{
}
