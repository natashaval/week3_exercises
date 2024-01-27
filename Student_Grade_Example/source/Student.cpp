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
    third.setGrade(5, 20);
    third.setGrade(6, 30);
    third.setGrade(1, 40);
    std::cout << "ID: " << third.getId() << " Grades: " << third.getGrades() << std::endl;

    std::optional<double> thirdAverageGrade = third.getAverageGrade();
    if (thirdAverageGrade.has_value())
    {
        std::cout << "Average grade: " << thirdAverageGrade.value() << " Award: " << third.getAward() << std::endl;
    }

    return 0;
}