#include "assignment.hpp"

Assignment::Assignment(const std::string &assignment_name, double total_points) {
    this->assignment_name = assignment_name;
    this->total_points = total_points;
}

std::string Assignment::get_assignment_name() const {
    return assignment_name;
}

double Assignment::get_total_points() const {
    return total_points;
}