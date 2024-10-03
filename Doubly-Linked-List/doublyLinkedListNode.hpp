#pragma once

#include <iostream>

template<typename T>
class Node
{
public:
	Node();
	Node(T value);
	Node(const Node& other) = delete;
	Node& operator=(const Node& other) = delete;
	Node(Node&& other) = delete;
	Node& operator=(Node&& other) = delete;
	~Node();

	Node<T>* getNext();
	Node<T>* getPrevious();
	T& getValue();

	void setNext(Node<T>* next);
	void setPrevious(Node<T>* previous);

private:
	Node<T>* m_next = nullptr;
	Node<T>* m_previous = nullptr;
	T m_value;
};

template<typename T>
Node<T>::Node()
{
	std::cout << "Node default constructor called.\n";
}

template<typename T>
Node<T>::Node(T value)
	: m_value{value}
{
	std::cout << "Node value constructor called with value " << value << ".\n";
}

template<typename T>
Node<T>::~Node()
{
	std::cout << "Node destructor called for value " << m_value << "!\n";
}

template<typename T>
Node<T>* Node<T>::getNext()
{
	return m_next;
}

template<typename T>
Node<T>* Node<T>::getPrevious()
{
	return m_previous;
}

template<typename T>
T& Node<T>::getValue()
{
	return m_value;
}

template<typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* previous)
{
	m_previous = previous;
}

