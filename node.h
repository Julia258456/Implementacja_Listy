#pragma once
#include <iostream>

template <class T>
class Node
{
public:
	Node(T val);
	~Node();
	Node* next, * prev;
	T value;
};

template <class T>
Node<T>::Node(T val) {
	value = val;
	next = prev = nullptr;
	std::cout << "Node(T)" << std::endl;
}

template <class T>
Node<T>::~Node() {
	if (next && prev) {
		next->prev = prev;
		prev->next = next;
	}
	next = prev = nullptr;
	std::cout << "~Node()"  << std::endl;
}
