#pragma once

#include <vector>
#include <string>
#include <sstream>
#include "student.hpp"
#include "assignment.hpp"

class Gradebook {
private:
    std::vector<Student> students;              // Vector of students
    std::vector<Assignment> assignments;        // Vector of assignments
    std::vector<std::vector<double>> grades;    // Vector of grades

public:
    void add_student(const std::string &first_name, const std::string &last_name, int ID);
    void add_assignment(const std::string &name, double total_points);
    void enter_grade(int student_ID, const std::string &assignment_name, double grade);
    std::string report() const;
};
