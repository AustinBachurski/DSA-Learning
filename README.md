# Learning Data Structures

Doubly Linked List is an attempt at implementing a `std::list`, strictly for learning/understanding purposes. 

- Constructors/destructors for the list itself as well as the nodes contain print statements to show what's going on - as a result `T` must be printable, which is enforced by a concept.
- The list does feature a forward iterator and as such works with range based loops and C++ 20 `ranges`.

### Member Functions
| Insertion         | Removal       | Capacity     | Element Access | Iterators |
|-------------------|---------------|--------------|----------------|-----------|
| `push_back()`     | `clear()`     | `length()`   | `operator[]`   | `begin()` |
|`push_front()`     | `remove_at()` |  `size()`    | `front()`      | `end()`   |
| `insert_at()`     | `pop_back()`  | `is_empty()` | `back()`       |           |
| `append_range()`  | `pop_front()` |              |                |           |
| `prepend_range()` |               |              |                |           |

>Although not really appropriate, I did implement `operator[]` and constructors taking a single value as well as a `std::initializer_list` for learning purposes.

### A Brief Demo

>main.cpp produces the following:
```console
**Demo Start**

List of type int:
List constructor called with initializer list.
Node value constructor called with value 1.
Node value constructor called with value 2.
Node value constructor called with value 3.
Node value constructor called with value 4.
Node value constructor called with value 5.

Clear the list.
Node destructor called for value 1!
Node destructor called for value 2!
Node destructor called for value 3!
Node destructor called for value 4!
Node destructor called for value 5!

List Size: 0

Leave this scope.
List destructor called!

List of type std::string:
List default constructor called.

Insertion Operations:
Node value constructor called with value Six.
Node value constructor called with value Four.
Node value constructor called with value Three.
Node value constructor called with value Two.
Node value constructor called with value One.
Node value constructor called with value Seven.
Node value constructor called with value Eight.
Node value constructor called with value Nine.
Node value constructor called with value Five.

Range based for loop.
One
Two
Three
Four
Five
Six
Seven
Eight
Nine

Remove Operations:
Node destructor called for value Nine!
Node destructor called for value Eight!
Node destructor called for value Seven!
Node destructor called for value Six!
Node destructor called for value Five!
Node destructor called for value Three!
Node destructor called for value One!

Swap Elements 0 and 1.

Obligatory List Contents:
Four, Two

Leave this scope.
List destructor called!
Node destructor called for value Four!
Node destructor called for value Two!

**Demo End**
```
