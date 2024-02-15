add_library(student_lib Student.cpp)
target_include_directories(student_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# add executable 
add_executable(StudentGrades main.cpp)
target_link_libraries(StudentGrades PUBLIC student_lib)