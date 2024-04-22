#pragma once
#include "Doubly Linked List Node.hpp"
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>


template<typename T>
class DoublyLinkedList
{
public:
	class Iterator
	{
	public:
		Iterator(Node<T>* pointer) : m_pointer{ pointer } {}

		Iterator& operator++() 
		{ 
			m_pointer = m_pointer->getNext();
			return *this;
		}

		Iterator& operator++(int) 
		{ 
			Node<T>* old = m_pointer; 
			m_pointer = m_pointer->getNext();
			return *old;
		}
		
		bool operator==(const Iterator other) const
		{
			return m_pointer == other.m_pointer;
		}

		bool operator!=(const Iterator other) const
		{
			return m_pointer != other.m_pointer;
		}

		T& operator*() const
		{
			return m_pointer->getValue();
		}

		Node<T>* m_pointer;
	};

public:
	DoublyLinkedList();
	DoublyLinkedList(T value);
	DoublyLinkedList(std::initializer_list<T> values);
	~DoublyLinkedList();  // TODO: Rule of 5!
	
	Iterator begin()
	{
		return Iterator(m_head);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}

	size_t length();
	size_t size();

	void push_back(T value);
	void push_front(T value);
	void insert(T value, size_t index);
	void append_range(std::initializer_list<T> values);
	void prepend_range(std::initializer_list<T> values);

	T& operator[](size_t index);

	void clear();
	void erase(size_t index);
	void pop_back();
	void pop_front();
	void swap(size_t a, uint64_t b);

private:
	Node<T>* backwards_to(size_t index);
	Node<T>* foward_to(size_t index);
	Node<T>* walk_to(size_t index);
	
	Node<T>* m_head = nullptr;
	size_t m_length = 0;
	Node<T>* m_tail = nullptr;
	
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T value)
{
	m_head = new Node<T>(value);
	m_tail = m_head;
	++m_length;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> values)
{
	append_range(values);
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	std::cout << "List destructor called!" << std::endl;
	clear();
}

template<typename T>
size_t DoublyLinkedList<T>::length()
{
	return m_length;
}

template<typename T>
size_t DoublyLinkedList<T>::size()
{
	return length();
}

template<typename T>
void DoublyLinkedList<T>::push_back(T value)
{
	if (!m_tail)
	{
		m_head = new Node<T>(value);
		m_tail = m_head;
		++m_length;
		return;
	}
	else
	{
		Node<T>* currentNode = new Node<T>(value);
		currentNode->setPrevious(m_tail);
		m_tail->setNext(currentNode);
		m_tail = currentNode;
		++m_length;
		return;
	}
}

template<typename T>
void DoublyLinkedList<T>::push_front(T value)
{
	if (!m_head)
	{
		m_head = new Node<T>(value);
		m_tail = m_head;
		++m_length;
		return;
	}
	else
	{
		Node<T>* currentNode = new Node<T>(value);
		currentNode->setNext(m_head);
		m_head->setPrevious(currentNode);
		m_head = currentNode;
		++m_length;
		return;
	}
}

template<typename T>
void DoublyLinkedList<T>::insert(T value, size_t index)
{
	Node<T>* target = walk_to(index);
	
	if (target)
	{
		if (target->getNext() && target->getPrevious())
		{
			Node<T>* newNode = new Node<T>(value);
			
			target->getPrevious()->setNext(newNode);
			newNode->setPrevious(target->getPrevious());
			target->setPrevious(newNode);
			newNode->setNext(target);
			++m_length;
			return;
		}
		else if (target->getPrevious())
		{
			push_back(value);
			return;
		}
		else
		{
			push_front(value);
			return;
		}
	}
	else
	{
		throw std::out_of_range("Index access at " + std::to_string(index) 
			+ " called with length " + std::to_string(m_length) + ".\n");
	}
}

template<typename T>
void DoublyLinkedList<T>::append_range(std::initializer_list<T> values)
{
	std::for_each(values.begin(), values.end(), [this](auto value)
		{
			push_back(value);
		});
}

template<typename T>
void DoublyLinkedList<T>::pop_back()
{
	if (m_tail)
	{
		if (m_tail->getPrevious())
		{
			m_tail = m_tail->getPrevious();
			delete m_tail->getNext();
			m_tail->setNext(nullptr);
			--m_length;
			return;
		}
		else
		{
			delete m_tail;
			m_tail = nullptr;
			m_head = nullptr;
			--m_length;
			return;
		}

	}
}

template<typename T>
void DoublyLinkedList<T>::pop_front()
{
	if (m_head)
	{
		if (m_head->getNext())
		{
			m_head = m_head->getNext();
			delete m_head->getPrevious();
			m_head->setPrevious(nullptr);
			--m_length;
			return;
		}
		else
		{
			delete m_head;
			m_head = nullptr;
			m_tail = nullptr;
			--m_length;
			return;
		}
	}
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
	if (m_head)
	{
		Node<T>* next = m_head;
		m_head = nullptr;
		m_tail = nullptr;

		while (next)
		{
			if (next->getNext())
			{
				Node<T>* current = next;
				next = current->getNext();
				delete current;
			}
			else
			{
				delete next;
				next = nullptr;
			}
		}
		m_length = 0;
	}
	return;
}

template<typename T>
void DoublyLinkedList<T>::erase(size_t index)
{
	Node<T>* target = walk_to(index);

	if (target->getNext() && target->getPrevious())
	{
		target->getNext()->setPrevious(target->getPrevious());
		target->getPrevious()->setNext(target->getNext());
		delete target;
		target = nullptr;
		--m_length;
		return;
	}
	else if (target->getPrevious())
	{
		pop_back();
		return;
	}
	else
	{
		pop_front();
		return;
	}
}

template<typename T>
void DoublyLinkedList<T>::swap(size_t a, uint64_t b)
{
	Node<T>* nodeA = walk_to(a);
	Node<T>* nodeB = walk_to(b);

	Node<T>* nodeBnext = nodeB->getNext();
	Node<T>* nodeBprevious = nodeB->getPrevious();
	
	nodeA->getPrevious()->setNext(nodeB);
	nodeA->getNext()->setPrevious(nodeB);
	nodeB->getPrevious()->setNext(nodeA);
	nodeB->getNext()->setPrevious(nodeA);

	nodeB->setNext(nodeA->getNext());
	nodeB->setPrevious(nodeA->getPrevious());
	nodeA->setNext(nodeBnext);
	nodeA->setPrevious(nodeBprevious);
}

template<typename T>
T& DoublyLinkedList<T>::operator[](size_t index)
{
	return walk_to(index)->getValue();
}

template<typename T>
Node<T>* DoublyLinkedList<T>::walk_to(size_t index)
{
	if (index + 1 > m_length)
	{
		throw std::out_of_range("Index access at " + std::to_string(index) 
			+ " called with length " + std::to_string(m_length) + ".\n");
	}
	if (m_length > index + index)
	{
		return foward_to(index);
	}
	else
	{
		return backwards_to(index);
	}
}

template<typename T>
Node<T>* DoublyLinkedList<T>::backwards_to(size_t index)
{
	Node<T>* current = m_tail;

	for (size_t i = m_length; i > index + 1; --i)
	{
		current = current->getPrevious();
	}

	return current;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::foward_to(size_t index)
{
	Node<T>* current = m_head;

	for (size_t i = 0; i < index; ++i)
	{
		current = current->getNext();
	}
	
	return current;
}
