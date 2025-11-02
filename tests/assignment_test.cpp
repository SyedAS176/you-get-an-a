#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/assignment.hpp"

TEST_CASE("Assignment constructor initializes correctly") {
    Assignment a("Quiz 1", 100.0);

    REQUIRE(a.get_assignment_name() == "Quiz 1");
    REQUIRE(a.get_total_points() == 100.0);
}

TEST_CASE("Multiple assignments are independent") {
    Assignment a1("Lab 1", 50.0);
    Assignment a2("Project", 200.0);

    REQUIRE(a1.get_assignment_name() != a2.get_assignment_name());
    REQUIRE(a1.get_total_points() != a2.get_total_points());
}