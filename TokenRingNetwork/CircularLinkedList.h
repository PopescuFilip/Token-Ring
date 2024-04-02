#pragma once
#include "CircularListIterator.h"
#include <iostream>

template <typename T>
class CircularLinkedList
{
public:
	CircularListIterator<T> begin() const;

	void Print() const;

	void AddNode(const T& value);
private:
	std::shared_ptr<Node<T>> m_head;
};

template<typename T>
inline CircularListIterator<T> CircularLinkedList<T>::begin() const
{
	return CircularListIterator(m_head->next);
}

template<typename T>
inline void CircularLinkedList<T>::Print() const
{
	if (!m_head)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}

	std::shared_ptr<Node<T>> aux{ m_head->next };
	do
	{
		std::cout << aux->value << '\n';
		aux = aux->next;
	} while (aux != m_head->next);
	std::cout << std::endl;
}

template<typename T>
inline void CircularLinkedList<T>::AddNode(const T& value)
{
	std::shared_ptr<Node<T>> newNode{ new Node(value) };
	
	if (!m_head) 
	{
		m_head = newNode;
		m_head->next = m_head;
		return;
	}

	newNode->next = m_head->next;
	m_head->next = newNode;
	m_head = newNode;
}
