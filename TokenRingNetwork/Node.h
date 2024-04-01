#pragma once
template <typename T>
struct Node
{
	Node();
	Node(const T& value);

	T value;
	std::unique_ptr<Node<T>> next;
};

template<typename T>
inline Node<T>::Node()
{}

template<typename T>
inline Node<T>::Node(const T& value) :
	value{ value }
{}