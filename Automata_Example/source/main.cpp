#include "automaton.h"
#include <vector>
#include <map>
#include <iostream>

using std::vector;
using std::map;
using std::string;

int main()
{
    vector<vector<int>> M{{0, 1}, {0, 1}};
    map<char, int> A{{'a', 0}, {'b', 1}}; 
    vector<int> S{1};
    // vector<int> S;
    
    // try {
        Automaton ends_with_b(A, M, S);
    // } catch (std::range_error &e) {
        // std::cerr << "Range error: " << e.what() << std::endl;
    // }

    // Question: if we create try-catch in Automaton constructor, we'll get ‘ends_with_b’ was not declared in this scope in the second try-catch
    // Ans: No need to try catch here -> because the expected behaviour is to exit the program anyway; we can't continue

    try {
    std::cout << "Read abab = " << ends_with_b.Read("abab") << std::endl;
    std::cout << "Read aaba = " << ends_with_b.Read("aaba") << std::endl;

    // What happens when if alphabet.find(c) looks for a character which isn’t in the alphabet?
    // std::cout << "Read cccc = " << ends_with_b.Read("cccc") << std::endl;

    // What happens if we call Read more than once?
    std::cout << "Read aaab = " << ends_with_b.Read("aaaa").Read("ab") << std::endl;
    } catch (std::logic_error &e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception (general): " << e.what() << std::endl;
    }
    return 0;
}