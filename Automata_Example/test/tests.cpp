#include <catch2/catch_test_macros.hpp>
#include "automaton.h"
#include <vector>
#include <map>

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