#include "Doubly-Linked-List/doublyLinkedList.hpp"

#include <print>
#include <string>


int main()
{
	std::println("**Demo Start**");
	{
		std::println("\nList of type int:");
		DoublyLinkedList<int> list = { 1, 2, 3, 4, 5 };

		std::println("\nClear the list.");
		list.clear();

		std::println("\nList Size: {}", list.size());
		std::println("\nLeave this scope.");
	}

	{
		std::println("\nList of type std::string:");
		DoublyLinkedList<std::string> list;

		std::println("\nInsertion Operations:");
		list.push_back("Six");
		list.push_front("Four");
		list.prepend_range({ "One", "Two", "Three" });
		list.append_range({ "Seven", "Eight", "Nine" });
		list.insert_at("Five", 4);

		std::println("\nRange based for loop.");
		for (const auto& x : list)
		{
			std::println("{}", x);
		}

		std::println("\nRemove Operations:");
		list.pop_back();
		list.pop_back();
		list.pop_back();
		list.pop_back();
		list.pop_back();
		list.remove_at(2);
		list.pop_front();

		std::println("\nSwap Elements 0 and 1.");
		list.swap(0, 1);

		std::println("\nObligatory List Contents:");
		std::println("{}, {}", list.front(), list.back());

		std::println("\nLeave this scope.");
	}

	std::println("\n**Demo End**");
}
