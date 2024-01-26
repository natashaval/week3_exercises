#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

using std::vector;
using std::map;
using std::string;

class Automaton
{
    public: 
    Automaton(map<char, int> A, vector<vector<int>> M, vector<int> S);

    bool Read(string word);

    private:
    int state = 0;
    map<char, int> alphabet;
    vector<vector<int>> transition_matrix;
    vector<int> accepting_states;
};

#endif
