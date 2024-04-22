#pragma once
#include <iostream>

template<typename T>
class Node
{
public:
	Node();
	Node(T value);
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
	std::cout << "Default constructor called." << std::endl;
}

template<typename T>
Node<T>::Node(T value)
	: m_value{value}
{
	std::cout << "Single value constructor called with value " << value << '.' << std::endl;
}

template<typename T>
Node<T>::~Node()
{
	std::cout << "Node destructor called for value " << m_value << '!' << std::endl;
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

