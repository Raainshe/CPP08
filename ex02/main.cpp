/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:18:12 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 14:51:09 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>

void testBasicOperations() {
    std::cout << "=== Testing Basic Stack Operations ===" << std::endl;
    
    MutantStack<int> mstack;
    
    // Test empty stack
    std::cout << "Empty stack size: " << mstack.size() << std::endl;
    std::cout << "Is empty: " << (mstack.empty() ? "true" : "false") << std::endl;
    
    // Test push and size
    mstack.push(5);
    mstack.push(17);
    std::cout << "After pushing 5, 17 - Size: " << mstack.size() << std::endl;
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    // Test pop
    mstack.pop();
    std::cout << "After pop - Size: " << mstack.size() << std::endl;
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    std::cout << std::endl;
}

void testNewMethods() {
    std::cout << "=== Testing New push_back/pop_back Methods ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push_back(3); // Should add to back
    mstack.push_back(4); // Should add to back
    
    std::cout << "Stack contents after push(1), push(2), push_back(3), push_back(4):" << std::endl;
    for (auto it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    mstack.pop_back(); // Remove from back
    std::cout << "After pop_back():" << std::endl;
    for (auto it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

void testIterators() {
    std::cout << "=== Testing Iterator Functionality ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    // Test forward iteration
    std::cout << "Forward iteration:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Test iterator operations
    std::cout << "Testing iterator increment/decrement:" << std::endl;
    it = mstack.begin();
    std::cout << "First element: " << *it << std::endl;
    ++it;
    std::cout << "Second element: " << *it << std::endl;
    --it;
    std::cout << "Back to first element: " << *it << std::endl;
    
    std::cout << std::endl;
}

void testCopyOperations() {
    std::cout << "=== Testing Copy Constructor and Assignment ===" << std::endl;
    
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);
    
    // Test copy constructor
    MutantStack<int> copied(original);
    std::cout << "Original stack:" << std::endl;
    for (auto it = original.begin(); it != original.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copied stack:" << std::endl;
    for (auto it = copied.begin(); it != copied.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test assignment operator
    MutantStack<int> assigned;
    assigned.push(99);
    assigned = original;
    std::cout << "Assigned stack:" << std::endl;
    for (auto it = assigned.begin(); it != assigned.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Modify original to show independence
    original.push(4);
    std::cout << "After modifying original (should not affect copies):" << std::endl;
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copied size: " << copied.size() << std::endl;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    
    std::cout << std::endl;
}

void testStdStackCompatibility() {
    std::cout << "=== Testing std::stack Compatibility ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    
    // Test conversion to std::stack
    std::stack<int> stdStack(mstack);
    std::cout << "std::stack size after conversion: " << stdStack.size() << std::endl;
    std::cout << "std::stack top: " << stdStack.top() << std::endl;
    
    // Show that std::stack works normally
    stdStack.pop();
    std::cout << "After pop - std::stack size: " << stdStack.size() << std::endl;
    std::cout << "std::stack top: " << stdStack.top() << std::endl;
    
    std::cout << std::endl;
}

void testWithDifferentTypes() {
    std::cout << "=== Testing with Different Types ===" << std::endl;
    
    // Test with strings
    MutantStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("!");
    
    std::cout << "String stack contents:" << std::endl;
    for (auto it = stringStack.begin(); it != stringStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test with doubles
    MutantStack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    doubleStack.push(1.41);
    
    std::cout << "Double stack contents:" << std::endl;
    for (auto it = doubleStack.begin(); it != doubleStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

void runOriginalTest() {
    std::cout << "=== Original Test from Subject ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << std::endl;
}

int main()
{
    testBasicOperations();
    testNewMethods();
    testIterators();
    testCopyOperations();
    testStdStackCompatibility();
    testWithDifferentTypes();
    runOriginalTest();
    
    // Bonus: Show the key advantage of MutantStack
    std::cout << "=== MutantStack vs std::stack Comparison ===" << std::endl;
    
    MutantStack<int> mstack;
    std::stack<int> stdstack;
    
    // Add same elements to both
    for (int i = 1; i <= 5; ++i) {
        mstack.push(i);
        stdstack.push(i);
    }
    
    std::cout << "MutantStack contents (using iterators):" << std::endl;
    for (auto it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "std::stack contents (no iterators available):" << std::endl;
    std::cout << "Can only access top element: " << stdstack.top() << std::endl;
    std::cout << "To see all elements, we'd need to pop them (destructive operation)" << std::endl;
    
    std::cout << std::endl;
    std::cout << "=== All Tests Completed Successfully! ===" << std::endl;
    
    return 0;
}