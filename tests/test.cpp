
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "../include/algos.hpp"

TEST_CASE("removeDuplicates removes adjacent pairs repeatedly", "[removeDuplicates]") {
	REQUIRE(removeDuplicates(std::string("abbaca")) == "ca");
	REQUIRE(removeDuplicates(std::string("azxxzy")) == "ay");
	REQUIRE(removeDuplicates(std::string("abccba")) == "");
	REQUIRE(removeDuplicates(std::string("")) == "");
	REQUIRE(removeDuplicates(std::string("a")) == "a");
}

TEST_CASE("clean_backspace_string simulates backspace '<' correctly", "[clean_backspace_string]") {
	REQUIRE(clean_backspace_string(std::string("ab<c")) == "ac");
	REQUIRE(clean_backspace_string(std::string("a<<")) == "");
	REQUIRE(clean_backspace_string(std::string("abc<d<<e")) == "ae");
	REQUIRE(clean_backspace_string(std::string("")) == "");
}

TEST_CASE("stack_contains_restore finds element and restores order", "[stack_contains_restore]") {
	std::stack<int> S;
	std::queue<int> Q;

	// push 1..5 so 5 is top
	for (int i = 1; i <= 5; ++i) S.push(i);

	// Search for middle element
	bool found = stack_contains_restore<int>(S, Q, 3);
	REQUIRE(found == true);

	// After call, stack should be unchanged (top should still be 5)
	REQUIRE(!S.empty());
	REQUIRE(S.top() == 5);

	// Pop elements to verify full order: expected 5,4,3,2,1
	std::vector<int> vals;
	while (!S.empty()) { vals.push_back(S.top()); S.pop(); }
	REQUIRE(vals == std::vector<int>({5,4,3,2,1}));

	// Now test not-found case
	for (int i = 1; i <= 3; ++i) S.push(i); // stack top = 3
	bool found2 = stack_contains_restore<int>(S, Q, 42);
	REQUIRE(found2 == false);
	REQUIRE(S.top() == 3);
	vals.clear();
	while (!S.empty()) { vals.push_back(S.top()); S.pop(); }
	REQUIRE(vals == std::vector<int>({3,2,1}));
}
