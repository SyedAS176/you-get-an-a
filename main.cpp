#include <iostream>
#include "src/gradebook.hpp"
using namespace std;

int main() {
  Gradebook gradebook;

  // Add students
  string first1 = "Bob", last1 = "Bobberson";
  string first2 = "Sam", last2 = "Sammerson";
  string first3 = "Jess", last3 = "Jesserson";

  gradebook.add_student(first1, last1, 123);
  gradebook.add_student(first2, last2, 456);
  gradebook.add_student(first3, last3, 789);

  // Add assignments
  string a1 = "Quiz 1";
  string a2 = "Lab 1";

  gradebook.add_assignment(a1, 100);
  gradebook.add_assignment(a2, 50);

  // Enter grades
  gradebook.enter_grade(456, a1, 95); // Sam Quiz 1
  gradebook.enter_grade(123, a1, 85); // Bob Quiz 1
  gradebook.enter_grade(789, a2, 49); // Jess Lab 1
  gradebook.enter_grade(789, a1, 93); // Jess Quiz 1
  gradebook.enter_grade(123, a2, 0);  // Bob Lab 1

  // Print final report
  cout << gradebook.report();

  return 0;
}
