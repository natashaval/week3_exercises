#include "automaton.h"

Automaton::Automaton(map<char, int> A, vector<vector<int>> M, vector<int> S) : alphabet(A), transition_matrix(M), accepting_states(S) {
    if (S.empty()) {
        throw std::range_error("Accepting states should be at least 1");
    }
    if (A.empty()) {
        throw std::range_error("Alphabet nodes should be at least 1");
    }
    // check the size of matrix A
}

bool Automaton::Read(string word)
{
    for (auto &c : word)
    {
        // check if char available in map
        if (alphabet.find(c) == alphabet.end()) {
            throw std::logic_error("cannot find character in alphabet map");
        }

        // a map's find method returns an iterator to the key-value pair for the given key
        // iterators have syntax similar to pointers: 
        // (*it) gives the key-value pair
        // -> can be used to access methods of the key value pair
        auto it = alphabet.find(c);

        //it->first gives the key, it->second gives the value
        int j = it->second;
        state = transition_matrix[state][j];
    }

    return std::find(accepting_states.begin(), accepting_states.end(), state) != accepting_states.end();
}
