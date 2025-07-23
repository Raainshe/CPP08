# CPP08 - STL Containers and Algorithms

This project explores C++ STL (Standard Template Library) containers, algorithms, and iterators through three progressive exercises. Each exercise demonstrates different aspects of working with templated classes and STL components.

## 📋 Table of Contents

- [Project Overview](#project-overview)
- [Exercise 00: easyfind](#exercise-00-easyfind)
- [Exercise 01: Span](#exercise-01-span)  
- [Exercise 02: MutantStack](#exercise-02-mutantstack)
- [Compilation](#compilation)
- [Usage Examples](#usage-examples)
- [Key Concepts](#key-concepts)

## 🎯 Project Overview

**CPP08** focuses on:
- **STL Containers**: Vector, Stack, List
- **STL Algorithms**: `std::find`, `std::sort`, `std::min_element`, `std::max_element`
- **Template Programming**: Function templates and class templates
- **Iterator Patterns**: Forward iterators and container iteration
- **Exception Handling**: Custom exceptions and error management

---

## 🔍 Exercise 00: easyfind

### Description
A template function that searches for the first occurrence of an integer value in any STL container.

### Features
- **Template Function**: Works with any STL container that supports iterators
- **STL Algorithm Integration**: Uses `std::find` for efficient searching
- **Exception Safety**: Throws custom exception when value is not found
- **Iterator-based**: Returns the distance from beginning to found element

### Files
- `easyfind.hpp` - Function declaration and includes
- `easyfind.tpp` - Template implementation
- `main.cpp` - Test cases and demonstrations

### Key Implementation
```cpp
template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return std::distance(container.begin(), it);
}
```

---

## 📊 Exercise 01: Span

### Description
A class that stores a collection of integers with a fixed maximum capacity and can calculate spans (differences) between stored numbers.

### Features
- **Capacity Management**: Fixed-size container with overflow protection
- **Shortest Span**: Finds minimum difference between any two stored numbers
- **Longest Span**: Calculates difference between maximum and minimum values
- **Exception Handling**: Custom exception for capacity exceeded scenarios
- **STL Integration**: Uses `std::vector` internally with STL algorithms

### Class Interface
```cpp
class Span {
    public:
        Span(unsigned int N);              // Constructor with capacity
        void addNumber(int number);        // Add single number
        int shortestSpan();               // Find minimum span
        int longestSpan();                // Find maximum span
        
        class SpanIsFull : public std::exception;  // Custom exception
};
```

### Algorithms Used
- **Sorting**: `std::sort` for efficient shortest span calculation
- **Min/Max**: `std::min_element` and `std::max_element` for longest span
- **Adjacent Comparison**: Iterates through sorted array for minimum differences

---

## 🔄 Exercise 02: MutantStack

### Description
A stack container that provides iterator functionality, combining the LIFO (Last In, First Out) behavior of a stack with the iteration capabilities typically found in other STL containers.

### Features
- **Stack Interface**: Standard stack operations (push, pop, top, empty, size)
- **Iterator Support**: Forward iteration through stack elements
- **STL Compatibility**: Convertible to `std::stack` for interoperability
- **Template Design**: Works with any data type
- **Additional Operations**: Extended with `push_back` and `pop_back` methods

### Class Interface
```cpp
template <typename T>
class MutantStack {
    public:
        // Stack operations
        void push(const T &value);
        void pop();
        T &top();
        bool empty() const;
        size_t size() const;
        
        // Iterator functionality
        iterator begin();
        iterator end();
        
        // Extended operations
        void push_back(const T &value);
        void pop_back();
};
```

### Internal Implementation
- **Container**: Uses `std::list` as underlying storage
- **Iterator Types**: Provides both `iterator` and `const_iterator`
- **Stack Semantics**: Push/pop operations work on the front of the list
- **Conversion Operator**: Seamless conversion to `std::stack`

---

## 🛠️ Compilation

Each exercise can be compiled independently using the provided Makefiles.

### Compile All Exercises
```bash
# Compile all exercises at once
make -C ex00 && make -C ex01 && make -C ex02
```

### Compile Individual Exercises
```bash
# Exercise 00
cd ex00
make
./easyfind

# Exercise 01  
cd ex01
make
./span

# Exercise 02
cd ex02
make
./mutantstack
```

### Makefile Targets
- `make` - Compile the exercise
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Clean and recompile

### Compilation Flags
All exercises are compiled with:
- `-Wall -Wextra -Werror` - Enable all warnings and treat them as errors
- `-std=c++17` - Use C++17 standard

---

## 🚀 Usage Examples

### Exercise 00: easyfind

```bash
$ ./easyfind
3
2
runtime_error: Value not found
--------------------------------
```

**Example Usage:**
```cpp
std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
try {
    std::cout << easyfind(vec, 3) << std::endl;  // Output: 3
    std::cout << easyfind(vec, 2) << std::endl;  // Output: 2
    std::cout << easyfind(vec, 10) << std::endl; // Throws exception
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

### Exercise 01: Span

```bash
$ ./span
2
14
--------------------------------
Personal tests
2
99998
```

**Example Usage:**
```cpp
Span sp(5);
sp.addNumber(17);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl;  // Output: 2 (9-11 or 6-3)
std::cout << sp.longestSpan() << std::endl;   // Output: 14 (17-3)
```

### Exercise 02: MutantStack

```bash
$ ./mutantstack
=== Testing Basic Stack Operations ===
Empty stack size: 0
Is empty: true
After pushing 5, 17 - Size: 2
Top element: 17
After pop - Size: 1
Top element: 5

=== Testing Iterator Functionality ===
Forward iteration:
0
737
5
3

=== All Tests Completed Successfully! ===
```

**Example Usage:**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);

// Use as regular stack
std::cout << mstack.top() << std::endl;  // Output: 17
mstack.pop();

// Use with iterators
for (auto it = mstack.begin(); it != mstack.end(); ++it) {
    std::cout << *it << std::endl;
}

// Convert to std::stack
std::stack<int> s(mstack);
```

---

## 🧠 Key Concepts

### Template Programming
- **Function Templates**: Generic functions that work with multiple types
- **Class Templates**: Generic classes with type parameters
- **Template Specialization**: Customizing templates for specific types
- **Type Deduction**: Automatic type inference by the compiler

### STL Components

#### Containers
- **std::vector**: Dynamic array with random access
- **std::stack**: LIFO container adapter
- **std::list**: Doubly-linked list with bidirectional iteration

#### Algorithms
- **std::find**: Linear search algorithm
- **std::sort**: Efficient sorting algorithm
- **std::min_element/max_element**: Finding extremes in containers
- **std::distance**: Calculate distance between iterators

#### Iterators
- **Forward Iterators**: Single-pass, forward-only iteration
- **Bidirectional Iterators**: Forward and backward iteration
- **Iterator Categories**: Different types with varying capabilities
- **Iterator Traits**: Type information about iterators

### Exception Handling
- **Custom Exceptions**: Creating domain-specific error types
- **Exception Safety**: Writing exception-safe code
- **RAII Pattern**: Resource Acquisition Is Initialization
- **Exception Specifications**: Modern C++ exception handling

### Design Patterns
- **Container Adapters**: Providing different interfaces to existing containers
- **Template Method Pattern**: Defining algorithms with customizable steps
- **Iterator Pattern**: Providing sequential access to elements
- **Facade Pattern**: Simplifying complex subsystem interfaces

### Modern C++ Features
- **Auto Type Deduction**: Automatic type inference
- **Range-based For Loops**: Simplified iteration syntax
- **Smart Pointers**: Automated memory management
- **Move Semantics**: Efficient resource transfer

---

## 📝 Notes

- All exercises demonstrate progressive complexity in STL usage
- Error handling is implemented throughout with appropriate exceptions
- Code follows C++17 standards and best practices
- Memory management is handled automatically by STL containers
- Each exercise builds upon concepts from previous ones

## 🎓 Learning Outcomes

After completing this project, you will understand:
- How to create and use template functions and classes
- STL container characteristics and appropriate usage scenarios
- Iterator concepts and implementation patterns
- Exception handling strategies in C++
- Integration between different STL components
- Performance considerations in algorithm selection

---

## 👤 Author

**rmakoni** - [rmakoni@student.42heilbronn.de](mailto:rmakoni@student.42heilbronn.de)

*Project completed as part of the 42 School curriculum*