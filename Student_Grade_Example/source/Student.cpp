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
    if (grade >= 0 && grade <= 100)
    {
        grades.at(position) = grade;
    }
    else
    {
        throw std::domain_error("Grades must be between 0 and 100.");
    }
    return grade;
}

std::optional<double> Student::getAverageGrade()
{
    double total = 0.0;
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
        averageGrade = total / count;
        setAward(averageGrade.value());
        return averageGrade;
    }
}

Award Student::setAward(double averageGrade)
{
    if (averageGrade > 70)
    {
        myFinalGrade = Award::First;
    }
    else if (averageGrade > 50)
    {
        myFinalGrade = Award::Second;
    }
    else
    {
        myFinalGrade = Award::Fail;
    }
    return myFinalGrade;
}

std::string Student::getAward()
{
    switch (myFinalGrade)
    {
    case Award::First:
        return "First";
    case Award::Second:
        return "Second";
    default:
        return "Fail";
    }
}