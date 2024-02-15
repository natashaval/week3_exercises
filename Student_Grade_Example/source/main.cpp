#include <optional>
#include <iostream>
#include <algorithm>
#include "Student.hpp"

int main()
{
    Student first;
    first.setGrade(0, 100);
    first.setGrade(1, 50);
    first.setGrade(2, 70);
    std::cout << "ID: " << first.getId() << " Grades: " << first.getGrades() << std::endl;

    std::optional<double> firstAverageGrade = first.getAverageGrade();
    if (firstAverageGrade.has_value())
    {
        std::cout << "Average grade: " << firstAverageGrade.value() << " Award: " << first.getAward() << std::endl;
    }

    Student second;
    second.setGrade(2, 65);
    second.setGrade(3, 50);
    std::cout << "ID: " << second.getId() << " Grades: " << second.getGrades() << std::endl;

    std::optional<double> secondAverageGrade = second.getAverageGrade();
    if (secondAverageGrade.has_value())
    {
        std::cout << "Average grade: " << secondAverageGrade.value() << " Award: " << second.getAward() << std::endl;
    }

    Student third;
    third.setGrade(4, 10);
    third.setGrade(3, 20);
    third.setGrade(5, 30);
    third.setGrade(1, 40);
    std::cout << "ID: " << third.getId() << " Grades: " << third.getGrades() << std::endl;

    std::optional<double> thirdAverageGrade = third.getAverageGrade();
    if (thirdAverageGrade.has_value())
    {
        std::cout << "Average grade: " << thirdAverageGrade.value() << " Award: " << third.getAward() << std::endl;
    }

    return 0;
}