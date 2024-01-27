#include <optional>
#include <array>

enum class Award
{
    First,
    Second,
    Fail
};

class Student
{
    public:
        Student();
        ~Student() {}
        int getId();
        std::string getGrades();
        std::optional<int> setGrade(int position, int grade);
        std::optional<double> getAverageGrade();
        std::string getAward();

    // generate unique ID
    protected:
        static int ID;
    
    private:
        int id;
        std::array<std::optional<int>, 6> grades;
        std::optional<double> averageGrade;
        Award myFinalGrade;

        Award setAward(double averageGrade);
};