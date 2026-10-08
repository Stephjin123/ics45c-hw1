// stack.hpp
#pragma once
#include <iostream>
#include <string>

constexpr int STK_MAX = 1000;

class Stack {
    int _top;
    char buf[STK_MAX];

public:
    // constructs this Stack
    Stack() {
        _top = 0;
    }

    // adds c to the top of this Stack
    void push(char c) {
        if (!isFull()) {
            buf[_top] = c;
            _top++;
        }
    }

    // removes and returns the top character of this Stack
    char pop() {
        if (isEmpty()) {
            return '@';
        }
        _top--;
        return buf[_top];
    }

    // peeks at the top char and returns it without removing it
    char top() {
        if (isEmpty()) {
            return '@';
        }
        return buf[_top - 1];
    }

    // returns true iff this Stack is empty
    bool isEmpty() {
        return _top == 0;
    }

    // returns true iff this Stack is full
    bool isFull() {
        return _top == STK_MAX;
    }

// notice the class definition ends with a semicolon
};

// pushes every character of line onto stk
inline void push_all(Stack& stk, std::string line) {
    for (char c : line) {
        stk.push(c);
    }
}

// pops characters off stk and prints them to cout, all on one line
// with no extra spaces, followed by a newline
inline void pop_all(Stack& stk) {
    while (!stk.isEmpty()) {
        std::cout << stk.pop();
    }
    std::cout << std::endl;
}
