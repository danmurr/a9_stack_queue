#pragma once

#include <string>
#include <stack>
#include <queue>
#include <stdexcept>


/*
Remove Adjacent Duplicates Using Stack
Goal: Remove all adjacent duplicate characters until none remain
Example:
"abbaca" -> "ca"
"abccba" -> ""
Stack Logic:
Iterate over string s:
If stack top = current character, pop from stack (remove pair).
Else, push character onto stack.
Final stack gives the result string.
*/
std::string removeDuplicates(std::string s) {
    //ToDo
    if (s.empty()) return "";
    std::stack<char> charStack;
    for (char c : s) {
        if (!charStack.empty() && charStack.top() == c) {
            charStack.pop(); // Remove the adjacent duplicate
        } else {
            charStack.push(c); // Push current character onto stack
        }
    }
    // Construct the result string from the stack
    std::string result;
    while (!charStack.empty()) {
        result += charStack.top();
        charStack.pop();
    }
    std::reverse(result.begin(), result.end()); // Reverse to get correct order
    return result;
}

/*
clean string with Backspace char as <
Use stack to simulate typing
< = backspace -> pop from stack
Typing = push characters onto stack
Edge case: backspace on empty stack
Example:
s = "ab<c" -> stack = ['a', 'c']
t = "ad<c" -> stack = ['a', 'c']
*/
std::string clean_backspace_string(std::string s) {
    //ToDo
    std::stack<char> charStack;
    for (char c : s) {
        if (c == '<') {
            if (!charStack.empty()) {
                charStack.pop(); // Simulate backspace
            }
        } else {
            charStack.push(c); // Push character onto stack
        }
    }
}

/*
Suppose you have a stack S containing n elements and a queue Q that is
initially empty. 
Describe how you can use Q to scan S to see if it contains a certain element x, with the additional constraint that your algorithm must return the elements back to S in their original order. 
You may not use an array or linked list—only S and Q and a constant number of reference variables.

Scanning a Stack Using a Queue (While Preserving Order)
Goal: Check if element x is in stack S using only:
Stack S, empty queue Q, and constant variables
Preserve original order of S after scan
Steps:

Step 1: Pop from S, enqueue into Q, check for x
Step 2: After scanning, dequeue from Q, push into S
Step 3: Repeat: Pop from S, enqueue into Q (restores original order)
Step 4: Finally, dequeue from Q, push into S

Example:
S = [3, 1, 4] (top to bottom)
x = 1
After scan: S = [3, 1, 4], Q = [], and x found
*/


template <typename T>
bool stack_contains_restore(std::stack<T>& S, std::queue<T>& Q, const T& x) {
    //ToDo
    bool found = false;

    // Step 1: Pop all from S → enqueue into Q (scan for x)
    while (!S.empty()) {
        T val = S.top();
        S.pop();
        if (val == x) {
            found = true;
        }
        Q.push(val);
    }

    // Step 2: Move from Q → back into S
    // (Now S has elements in reverse order of original)
    while (!Q.empty()) {
        S.push(Q.front());
        Q.pop();
    }

    // Step 3: Pop again from S → enqueue into Q
    // (Restores original order)
    while (!S.empty()) {
        Q.push(S.top());
        S.pop();
    }
    
}