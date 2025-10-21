# A9: Stack Queue

In this assignment you will solve three problems using stack and queue. 

**You can use std::reverse when required.**

## Problem 1: Remove Adjacent Duplicates Using Stack

```cpp
std::string removeDuplicates(std::string s);
```

* Goal: Remove all adjacent duplicate characters in a string until none remain

* Example:

  * | Input        | Output  |
    | ------------ | ------- |
    | "abbaca"     | "ca"    |
    | "abccba"     | ""      |
    | ""           | ""      |
    | "abcde"      | "abcde" |
    | "aaaaa"      | "a"     |
    | "aaaa"       | ""      |
    | "1122334455" | ""      |
    | "abbaa"      | "a"     |

## Problem 2: Clean String that has backspace character <

```cpp
std::string clean_backspace_string(std::string s);
```

| Input    | Output |
| -------- | ------ |
| "ab<c"   | "ac"   |
| "ab<<"   | ""     |
| "a<<b<<" | ""     |
| "<"      | ""     |
| "<<a"    | "a"    |
| "a<bc<d" | "bd"   |



## Problem 3: Find element in a Stack (using a queue) without changing the order of the elements in the stack

Suppose you have a stack S containing n elements and a queue Q that is initially empty. Describe how you can use Q to scan S to see if it contains a certain element x, with the additional constraint that your algorithm must return the elements back to S in their original order.  You may not use an array or linked list—only S and Q and a constant number of reference variables.

Scanning a Stack Using a Queue (While Preserving Order)

The Queue must be initially empty

Goal: Check if element x is in stack S using only: Stack S, empty queue Q, and constant variables

Preserve original order of S after scan

```cpp
template <typename T>
bool stack_contains_restore(std::stack<T>& S, std::queue<T>& Q, const T& x);
```

| values before stack_contains_restore is called | return value                                         | values after stack_contains_restore is called |
| ---------------------------------------------- | ---------------------------------------------------- | --------------------------------------------- |
| S = {1, 2, 3, 4, 5}; Q={}; x=5                 | True                                                 | S = {1, 2, 3, 4, 5}; Q={}; x=5                |
| S = {1, 2, 3, 4, 5}; Q={}; x=1                 | True                                                 | S = {1, 2, 3, 4, 5}; Q={}; x=1                |
| S = {1, 2, 3, 4, 5}; Q={}; x=3                 | True                                                 | S = {1, 2, 3, 4, 5}; Q={}; x=5                |
| S = {1, 2, 3, 4, 5}; Q={}; x=10                | False                                                | S = {1, 2, 3, 4, 5}; Q={}; x=10               |
| S = {1, 2, 3, 4, 5}; Q={1}; x=3                | std::invalid_argument("Q must be initially empty."); | S = {1, 2, 3, 4, 5}; Q={1}; x=3               |
| S = {}; Q={}; x=5                              | False                                                | S = {}; Q={}; x=5                             |
| S = {5}; Q={}; x=5                             | True                                                 | S = {5}; Q={}; x=5                            |
| S = {5}; Q={}; x=10                            | False                                                | S = {5}; Q={}; x=5                            |

## Submissions:

* algos.hpp with implementation of above functions 
  * You should use std::stack, std::queue, std::string
* test.cpp with at least six test cases (can be based on above input/output)
* main.cpp is not required
* Negative Points for not following the instructions

## Rubrics:

* Autograder: 26 Points
* Test Cases: 9 Points (3 points for each problem)
* -2 points for build/exe uploads
* Negative Points for not following instructions 
