#include "gradebook.hpp"

// Add a new student
void Gradebook::add_student(const std::string &first_name, const std::string &last_name, int ID) {
    students.push_back(Student(first_name, last_name, ID));

    // New student: create a row with "none" (-1) for all existing assignments
    grades.push_back(std::vector<double>(assignments.size(), -1));
}

// Add a new assignment
void Gradebook::add_assignment(const std::string &name, double total_points) {
    assignments.push_back(Assignment(name, total_points));

    // Expand every student's row to include a new "none" (-1) grade; assignment was just added
    for (auto &row : grades) {
        row.push_back(-1);
    }
}

// Enter a grade for a student on an assignment
void Gradebook::enter_grade(int student_ID, const std::string &assignment_name, double grade) {
    int student_index = -1;
    int assignment_index = -1;

    // Find student index
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].get_ID() == student_ID) {
            student_index = i;
        }
    }

    // Find assignment index
    for (int j = 0; j < (int)assignments.size(); j++) {
        if (assignments[j].get_assignment_name() == assignment_name) {
            assignment_index = j;
        }
    }

    // If both found, assign the grade
    if (student_index != -1 && assignment_index != -1) {
        grades[student_index][assignment_index] = grade;
    }
}

// Generate a pretty report
std::string Gradebook::report() const {
    std::ostringstream out; // From <sstream>; concatenation is a pain so this is simple

    // Header row
    out << "Last_Name,First_Name,Student_ID";
    for (auto &a : assignments) {
        out << "," << a.get_assignment_name();
    }
    out << "\n";

    // Body
    for (int i = 0; i < (int)students.size(); i++) {
        out << students[i].get_last_name() << ","
            << students[i].get_first_name() << ","
            << students[i].get_ID();

        for (double g : grades[i]) {
            if (g < 0)
                out << ",none";
            else
                out << "," << g;
        }
        out << "\n";
    }
    return out.str();
}

// regarding line 5:
// I could also run this line apparently instead of the one above:
// students.emplace_back(firstName, lastName, ID);
// and that would have forwarded the arguments to the
// Student constructor but Push_back requires the object
// to be fully created and ready to push into the vector
// emplace_back calls Student(firstName, lastName, ID)
// inside the vector’s memory
// same for line 8