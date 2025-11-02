#include "student.hpp"

// Student constructor
Student::Student(const std::string &first_name, const std::string &last_name, int ID) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->ID = ID;
}

// Getter Methods
std::string Student::get_first_name() const {
    return first_name;
}

std::string Student::get_last_name() const {
    return last_name;
}

int Student::get_ID() const {
    return ID;
}