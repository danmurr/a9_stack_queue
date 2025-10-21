#pragma once

#include <string>
#include <stack>
#include <queue>
#include <stdexcept>
#include <algorithm>

/*
Remove Adjacent Duplicates Using Stack
*/
std::string removeDuplicates(std::string s) {
    if (s.empty()) return "";
    std::stack<char> charStack;
    for (char c : s) {
        if (!charStack.empty() && charStack.top() == c) {
            charStack.pop();
        } else {
            charStack.push(c);
        }
    }

    std::string result;
    while (!charStack.empty()) {
        result += charStack.top();
        charStack.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

/*
Clean string with Backspace char as <
*/
std::string clean_backspace_string(std::string s) {
    std::stack<char> charStack;
    for (char c : s) {
        if (c == '<') {
            if (!charStack.empty()) {
                charStack.pop();
            }
        } else {
            charStack.push(c);
        }
    }

    std::string result;
    while (!charStack.empty()) {
        result += charStack.top();
        charStack.pop();
    }
    std::reverse(result.begin(), result.end());
    return result; // ✅ missing in your version
}

/*
Check if x is in stack S using queue Q, restore original order
*/
template <typename T>
bool stack_contains_restore(std::stack<T>& S, std::queue<T>& Q, const T& x) {
    bool found = false;

    // Step 1: Move all from S → Q, check for x
    while (!S.empty()) {
        T val = S.top();
        S.pop();
        if (val == x)
            found = true;
        Q.push(val);
    }

    // Step 2: Move from Q → S (now reversed)
    while (!Q.empty()) {
        S.push(Q.front());
        Q.pop();
    }

    // Step 3: Move from S → Q (restores order)
    while (!S.empty()) {
        Q.push(S.top());
        S.pop();
    }

    // Step 4: Move from Q → S (final restore)
    while (!Q.empty()) {
        S.push(Q.front());
        Q.pop();
    }

    return found;
}
