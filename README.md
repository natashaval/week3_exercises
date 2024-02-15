# week3_exercises

[COMP0210 - Week 3](https://hackmd.io/@comp0210-cpp-redesign/H12IMwb7a)

[UCL Reading Week 3](https://github-pages.ucl.ac.uk/research-computing-with-cpp/03cpp2/)

[Week 3 Solutions](https://hackmd.io/@comp0210-cpp-redesign/B1I90eg56)

1. cmake -B build
- configuration
2. cmake --build build
- compilation the binary

How to run the executable:
- ./build/bin/Automata_example
> Read abab = 1
> Read aaba = 0


How to run the test:
- ./build/bin/automata_tests
> All tests passed (2 assertions in 1 test case)

Part 1 Solution:
Key Points:
- The dimensions of the transition matrix are checked. Every row must have the same number of elements as the number of characters.
- Every element in the transition matrix is checked to point to a valid state.
- Every accepting state is checked to be within the range of valid states.
  - You can also force there to be no repeated states in the accepting states list by using std::set(https://cplusplus.com/reference/set/set/) instead of a vector.
- Unsigned integers are used to avoid any negative numbers. They also prevent warnings when comparing with .size(), which returns an unsigned type (usually size_t).
- Member variables except for state are made const, since the state should be the only thing that varies once the DFA is defined.
- Read is modified to throw an exception if it encounters a character not in its alphabet. This prevents undefined behaviour (which is very bad!) when trying to access it->second.
- Alphabet map is manually constructed from a vector rather than entirely passed in. This prevents any characters being able to map to values that are outside the expected range. (For example, if we have just 3 letters in our alphabet, we should only create a map to the values [0,1,2]. If we let a user pass a map in, it could contain any values.)
- Read resets the state after reading the word so that it can be re-used.
- Variables passed into functions should be const where possible.