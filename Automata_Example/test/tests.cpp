#include <catch2/catch_test_macros.hpp>
#include "automaton.h"
#include <vector>
#include <map>
#include <memory>

using std::map;
using std::vector;

TEST_CASE("Check that a simple automaton accepts", "[simple accept]")
{
    vector<vector<int>> M{{0, 1}, {1, 1}};
    vector<int> S_A{0};
    map<char, int> A{{'a', 0}, {'b', 1}};
    Automaton only_As(A, M, S_A);

    REQUIRE(only_As.Read("aaaaa"));
    REQUIRE(!only_As.Read("aaaabaaa"));
    REQUIRE(only_As.Read(""));
}

TEST_CASE("Check that automaton failed", "[simple failed]")
{
    vector<vector<int>> M{{0, 1}, {1, 1}};
    vector<int> S_A{0};
    map<char, int> A{{'a', 0}, {'b', 1}};
    Automaton only_As(A, M, S_A);

    REQUIRE_THROWS_AS(only_As.Read("ccc"), std::logic_error);
}

// READ TWICE, check testcase
TEST_CASE("Check read twice, should reset", "[read twice]")
{
    vector<vector<int>> M{{0, 1}, {1, 0}};
    map<char, int> A{{'a', 0}, {'b', 1}};
    vector<int> S{1};
    
    Automaton odd_b(A, M, S);

    REQUIRE(odd_b.Read("abbb"));
    REQUIRE(odd_b.Read("babb"));
}

TEST_CASE("Check exception thrown if accepting states < 1", "[exception accepting states empty]")
{
    vector<vector<int>> M{{0, 1}, {0, 1}};
    map<char, int> A{{'a', 0}, {'b', 1}};
    vector<int> S;

    REQUIRE_THROWS_AS(Automaton(A, M, S), std::range_error);
}

// SOLUTION
TEST_CASE("Check matrix formatting", "[exceptions]")
{
    vector<vector<int>> M_long_row{{0,1,1}, {1, 1}};
    vector<vector<int>> M_short_row{{0,1}, {1}};
    vector<vector<int>> M_invalid_transition{{0,2}, {1,1}};
    vector<vector<int>> M_correct{{0,1},{1,1}};

    vector<int> S_A{0};
    map<char, int> A{{'a', 0}, {'b', 1}};
    std::unique_ptr<Automaton> only_As;
    REQUIRE_NOTHROW(only_As = std::make_unique<Automaton>(A, M_correct, S_A));
    REQUIRE_THROWS(only_As = std::make_unique<Automaton>(A, M_long_row, S_A));
    REQUIRE_THROWS(only_As = std::make_unique<Automaton>(A, M_short_row, S_A));
    // REQUIRE_THROWS(only_As = std::make_unique<Automaton>(A, M_invalid_transition, S_A));
}

TEST_CASE("Test accept states", "[exceptions]")
{
    vector<vector<int>> M_2states{{0,1},{1,1}};
    vector<vector<int>> M_3states{{2,1},{0,2},{1,0}};

    map<char, int> A{{'a', 0}, {'b', 1}};
    std::unique_ptr<Automaton> automaton;
    REQUIRE_NOTHROW(automaton = std::make_unique<Automaton>(A, M_2states, std::vector<int>{0}));
    REQUIRE_NOTHROW(automaton = std::make_unique<Automaton>(A, M_2states, std::vector<int>{1}));
    REQUIRE_NOTHROW(automaton = std::make_unique<Automaton>(A, M_2states, std::vector<int>{0, 1}));
    // REQUIRE_THROWS(automaton = std::make_unique<Automaton>(A, M_2states, std::vector<int>{2}));
    REQUIRE_THROWS(automaton = std::make_unique<Automaton>(A, M_2states, std::vector<int>{0,1,3}));

    REQUIRE_NOTHROW(automaton = std::make_unique<Automaton>(A, M_3states, std::vector<int>{0}));
    REQUIRE_NOTHROW(automaton = std::make_unique<Automaton>(A, M_3states, std::vector<int>{1}));
    // REQUIRE_NOTHROW(automaton = std::make_unique<Automaton>(A, M_3states, std::vector<int>{2}));
    REQUIRE_NOTHROW(automaton = std::make_unique<Automaton>(A, M_3states, std::vector<int>{0,1,2}));
    REQUIRE_THROWS(automaton = std::make_unique<Automaton>(A, M_2states, std::vector<int>{3}));
    REQUIRE_THROWS(automaton = std::make_unique<Automaton>(A, M_2states, std::vector<int>{0,4,2}));
}

TEST_CASE("Test strip function", "[strip]")
{
    map<char, int> A{{'a', 0}, {'b', 1}};
    string s1 = "aaaa";
    string s2 = "abbaab";
    string s3 = "aeabcab";
    string s4 = "cchdefj";
    
    // REQUIRE(strip(A, s1) == s1);
    // REQUIRE(strip(A, s2) == s2);
    // REQUIRE(strip(A, s3) == "aabab");
    // REQUIRE(strip(A, s4).empty());
    // REQUIRE(strip(A, "").empty());
}

TEST_CASE("Multiple Sequential Reads", "[multi-read]")
{
    // Define automaton that accepts strings with odd number of 'b's
    map<char, int> A{{'a', 0}, {'b', 1}};
    vector<vector<int>> M{{0, 1}, {1, 0}};
    vector<int> S{1};
    Automaton odd_num_b(A, M, S);

    // This is successful so final state is 1
    REQUIRE(odd_num_b.Read("ababab"));
    // If the state is not reset from 1 to 0 then the second read will fail
    REQUIRE(odd_num_b.Read("bbb"));
}