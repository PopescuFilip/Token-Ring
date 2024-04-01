#pragma once
template <typename T>
struct Node
{
	Node();
	Node(const T& value);

	T value;
	Node<T>* next;
};

template<typename T>
inline Node<T>::Node() :
	next{ nullptr }
{}

template<typename T>
inline Node<T>::Node(const T& value) :
	value{ value },
	next{ nullptr }
{}