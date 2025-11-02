#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/gradebook.hpp"

TEST_CASE("Adding students works") {
    Gradebook g;
    g.add_student("Alice", "Anderson", 101);
    g.add_student("Bob", "Bobberson", 202);

    std::string report = g.report();
    REQUIRE(report.find("Alice") != std::string::npos);
    REQUIRE(report.find("Bob") != std::string::npos);
}

TEST_CASE("Adding assignments works") {
    Gradebook g;
    g.add_assignment("Quiz 1", 100);
    g.add_assignment("Lab 1", 50);

    std::string report = g.report();
    REQUIRE(report.find("Quiz 1") != std::string::npos);
    REQUIRE(report.find("Lab 1") != std::string::npos);
}

TEST_CASE("Entering grades works") {
    Gradebook g;
    g.add_student("Alice", "Anderson", 101);
    g.add_student("Bob", "Bobberson", 202);
    g.add_assignment("Quiz 1", 100);
    g.add_assignment("Lab 1", 50);

    g.enter_grade(101, "Quiz 1", 95);
    g.enter_grade(202, "Quiz 1", 85);
    g.enter_grade(101, "Lab 1", 45);

    std::string report = g.report();
    REQUIRE(report.find("95") != std::string::npos);
    REQUIRE(report.find("85") != std::string::npos);
    REQUIRE(report.find("45") != std::string::npos);
}

TEST_CASE("Grades default to 'none' if not entered") {
    Gradebook g;
    g.add_student("Alice", "Anderson", 101);
    g.add_assignment("Quiz 1", 100);

    std::string report = g.report();
    REQUIRE(report.find("none") != std::string::npos);
}

TEST_CASE("Invalid student or assignment IDs do not crash") {
    Gradebook g;
    g.add_student("Alice", "Anderson", 101);
    g.add_assignment("Quiz 1", 100);

    g.enter_grade(999, "Quiz 1", 90);   // Non-existent student
    g.enter_grade(101, "Fake", 90);     // Non-existent assignment

    std::string report = g.report();
    REQUIRE(report.find("none") != std::string::npos); // Original remains
}