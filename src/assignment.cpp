#include "assignment.hpp"

Assignment::Assignment(const std::string &assignment_name, double totalPoints) {
    this->assignment_name = assignment_name;
    this->total_points = totalPoints;
}

std::string Assignment::get_assignment_name() const {
    return assignment_name;
}

double Assignment::get_total_points() const {
    return total_points;
}