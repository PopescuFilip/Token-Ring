#pragma once
#include "Node.h"

template <typename T>
class CircularListIterator
{
public:
	CircularListIterator(std::shared_ptr<Node<T>> head);

	T& operator*();

	CircularListIterator<T>& operator++();
private:
	std::shared_ptr<Node<T>> m_current;
};

template<typename T>
inline CircularListIterator<T>::CircularListIterator(std::shared_ptr<Node<T>> head):
	m_current{ head }
{}

template<typename T>
inline T& CircularListIterator<T>::operator*()
{
	return m_current->value;
}

template<typename T>
inline CircularListIterator<T>& CircularListIterator<T>::operator++()
{
	if (m_current)
		m_current = m_current->next;
	return *this;
}

