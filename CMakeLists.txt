cmake_minimum_required(VERSION 3.24)

project(you_get_an_a)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(main
        main.cpp
        src/gradebook.cpp
        src/student.cpp
        src/assignment.cpp
)

add_executable(student_test
        src/student.cpp
        tests/student_test.cpp
)

add_executable(assignment_test
        src/assignment.cpp
        tests/assignment_test.cpp
)

add_executable(gradebook_test
        src/gradebook.cpp
        src/student.cpp
        src/assignment.cpp
        tests/gradebook_test.cpp
)

target_link_libraries(student_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(assignment_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(gradebook_test PRIVATE Catch2::Catch2WithMain)