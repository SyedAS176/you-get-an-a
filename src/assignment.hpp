#pragma once

#include <string>

class Assignment {
private:
    std::string assignment_name;
    double total_points;

public:
    Assignment(const std::string &assignment_name, double total_points);
    std::string get_assignment_name() const;
    double get_total_points() const;
};