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

    // SOLUTION: why instantiate constructor above try/catch
    // In this case it's okay to call the constructor without a try/catch block because we don't want to continue the program without an Automaton created. If an exception is thrown by the constructor, then when it propagates to the top level and is not caught it will print the error message and terminate the program as desired.

    try {
    std::cout << "Read abab = " << ends_with_b.Read("abab") << std::endl;
    std::cout << "Read aaba = " << ends_with_b.Read("aaba") << std::endl;

    // What happens when if alphabet.find(c) looks for a character which isn’t in the alphabet?
    // std::cout << "Read cccc = " << ends_with_b.Read("cccc") << std::endl;

    // What happens if we call Read more than once?
    // ends_with_b.Read("aaaa").Read("ab") -> this one is wrong
    std::cout << "Read aaab = " << ends_with_b.Read("aaaa") << ends_with_b.Read("ab") << std::endl;
    std::cout << "Read aaab = " << ends_with_b.Read("aaab") << ends_with_b.Read("ab") << std::endl;
    } catch (std::logic_error &e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception (general): " << e.what() << std::endl;
    }
    return 0;
}