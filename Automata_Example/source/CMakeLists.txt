# add Library Automata_Lib

# create automaton.cpp as a Library
add_library(Automata_lib automaton.cpp)
# where to get header file
target_include_directories(Automata_lib PUBLIC ${CMAKE_SOURCE_DIR}/include) # from source directory (parent?) then include

# add executable 
add_executable(Automata_example main.cpp)
target_link_libraries(Automata_example PUBLIC Automata_lib)