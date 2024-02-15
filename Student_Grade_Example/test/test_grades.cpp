#include <catch2/catch_all.hpp>
#include "Student.hpp"
#include <optional>

using namespace Catch::Matchers;

TEST_CASE("Test average grades")
{
    Student test_student;
    test_student.setGrade(3, 50);
    test_student.setGrade(5, 55);

    REQUIRE_THAT(test_student.getAverageGrade().value(), WithinRel(52.5, 1e-5));
}

TEST_CASE("Test average for no grades")
{
    Student test_student;

    REQUIRE(!test_student.getAverageGrade().has_value());
}

TEST_CASE("Test set invalid grade")
{
    Student test_student;

    REQUIRE_THROWS(test_student.setGrade(8, 92));

    REQUIRE_THROWS(test_student.setGrade(0, 1492));
    REQUIRE_THROWS(test_student.setGrade(0, -50));
}