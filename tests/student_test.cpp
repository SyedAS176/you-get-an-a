#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/student.hpp"

TEST_CASE("Student constructor initializes correctly") {
    Student s("Alice", "Anderson", 101);

    REQUIRE(s.get_first_name() == "Alice");
    REQUIRE(s.get_last_name() == "Anderson");
    REQUIRE(s.get_ID() == 101);
}

TEST_CASE("Student getters return correct values") {
    Student s("Bob", "Bobberson", 202);

    REQUIRE(s.get_first_name() == "Bob");
    REQUIRE(s.get_last_name() == "Bobberson");
    REQUIRE(s.get_ID() == 202);
}

TEST_CASE("Multiple students are independent") {
    Student s1("Charlie", "Chaplin", 303);
    Student s2("Diana", "Dover", 404);

    REQUIRE(s1.get_first_name() != s2.get_first_name());
    REQUIRE(s1.get_ID() != s2.get_ID());
}