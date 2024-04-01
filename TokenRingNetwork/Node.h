#pragma once
template <typename T>
struct Node
{
	Node();
	Node(const T& value);

	T value;
	std::shared_ptr<Node<T>> next;
};

template<typename T>
inline Node<T>::Node() :
	next{ nullptr }
{}

template<typename T>
inline Node<T>::Node(const T& value) :
	next{ nullptr },
	value{ value }
{}