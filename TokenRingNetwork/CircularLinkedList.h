#pragma once
#include "Node.h"

template <typename T>
class CircularLinkedList
{
public:
	void AddNode(T value);
private:
	std::unique_ptr<Node<T>> m_head;
};

template<typename T>
inline void CircularLinkedList<T>::AddNode(T value)
{
}
