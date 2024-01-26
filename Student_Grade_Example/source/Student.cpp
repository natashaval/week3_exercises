#include <optional>
#include <iostream>
#include <algorithm>
#include "Student.hpp"

int Student::ID = 0;

// https://www.geeksforgeeks.org/how-to-get-a-unique-identifier-for-object-in-cpp/
Student::Student()
{
    id = ++ID;

    // std::fill_n(grades, sizeof(grades), std::nullopt);
}

int Student::getId()
{
    return id;
}

std::string Student::getGrades()
{
    std::string grades_string = "";
    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i].has_value())
        {
            grades_string.append(std::to_string(grades[i].value())).append(" ");
        }
    }
    return grades_string;
}

std::optional<int> Student::setGrade(int position, int grade)
{
    grades[position] = grade;
    return grade;
}

std::optional<double> Student::getAverageGrade()
{
    double total = 0;
    int count = 0;

    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i].has_value())
        {
            count++;
            total += grades[i].value();
        }
    }

    if (count == 0)
    {
        return std::nullopt;
    }
    else
    {
        return total / count;
    }
}

int main()
{
    Student first;
    // first.setGrade(0, 65);
    // first.setGrade(1, 50);
    std::cout << "ID: " << first.getId() << " Grades: " << first.getGrades() << std::endl;

    std::optional<double> firstAverageGrade = first.getAverageGrade();
    if (firstAverageGrade.has_value()) {
        std::cout << "Average grade: " << first.getAverageGrade().value() << std::endl;
    }

    Student second;
    std::cout << second.getId() << std::endl;

    Student third;
    std::cout << third.getId() << std::endl;

    return 0;
}