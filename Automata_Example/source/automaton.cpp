#include "automaton.h"

Automaton::Automaton(map<char, int> A, vector<vector<int>> M, vector<int> S) : alphabet(A), transition_matrix(M), accepting_states(S)
{
    if (S.empty())
    {
        throw std::range_error("Accepting states should be at least 1");
    }
    if (A.empty())
    {
        throw std::range_error("Alphabet nodes should be at least 1");
    }
    // check the size of matrix A
    uint num_states = transition_matrix.size();
    for (auto &row : transition_matrix)
    {
        if (row.size() != A.size())
        {
            throw std::logic_error("Each row in transition matrix must have one entry per character.");
        }
        for (auto &element : row)
        {
            if (element > num_states)
            {
                throw std::logic_error("Element found in transition matrix pointing to non existent state.");
            }
        }
    }

    // Check accepting states
    for (auto s : accepting_states) 
    {
        if (s > num_states)
        {
            throw std::logic_error("Invalid accepting state found.");
        }
    }
    if (accepting_states.size() > num_states)
    {
        throw std::logic_error("Size of accepting state vector should be less than or equal to the number states.");
    }
}

string Automaton::strip(const map<char, int> &A, string s)
{
    auto new_end = std::remove_if(s.begin(), s.end(), [&A](char a){return A.find(a) == A.end();});
    s.erase(new_end, s.end());
    return s;
}

bool Automaton::Read(string word)
{
    // reset state if we "Read" twice
    state = 0;

    for (auto &c : word)
    {
        // a map's find method returns an iterator to the key-value pair for the given key
        // iterators have syntax similar to pointers:
        // (*it) gives the key-value pair
        // -> can be used to access methods of the key value pair
        auto it = alphabet.find(c);

        // check if char available in map
        if (it == alphabet.end())
        {
            throw std::domain_error("Invalid character found in input string. You can try: " + strip(alphabet, word));
        }

        // it->first gives the key, it->second gives the value
        uint j = it->second;
        state = transition_matrix[state][j];

        // Question: What happens if we call Read more than once?
        // Answer: need to reset the state to '0' explanation in week 3 - more than once.jpg
    }

    return std::find(accepting_states.begin(), accepting_states.end(), state) != accepting_states.end();
}
