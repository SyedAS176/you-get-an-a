# You Get an A (C++) — CSC 122

## Overview

You can find the instructions for this lab at [More Than Equations][more-than-equations]. Create a new repository on GitHub to house your code. Be sure to make the repository public so that I can view and grade it.

We will use [CMake][cmake] to build executables (e.g. tests, the driver program, the benchmarks, etc.). Additionally, we will use [Catch2][catch2] for unit testing and benchmarking.

This project implements a simple, object-oriented gradebook system in C++ for CSC 122.  
It allows you to manage students, assignments, and grades — and generate a clean, formatted report that displays all the information in a CSV-style table.
**Later I will work on the add-ons for the gradebook system.**

---

## How to Use

### Creating a Gradebook
```cpp
Gradebook gradebook;
```

### Adding Students
```cpp
gradebook.add_student("John", "Wick", 123); // Student's first name, last name, and ID number
```

### Adding Assignments
```cpp
gradebook.add_assignment("Exam 1", 100); // Assignment name, assignment score
```

### Entering Grades
```cpp
gradebook.enter_grade(123, "Exam 1", 95); // John Wick, Exam 1, 95 points earned
```

### Generating a Report
```cpp
cout << gradebook.report();
```

## Building Executables With CMake

You can use CMake to compile and build the executables for the project. First, you need to create a `build/` directory in the project. The build directory will house all of the compiled files as well as the `Makefile` for the project. Note that we do NOT check the `build/` directory into version control since each person will have to regenerate the executables on their own machine.

```bash
mkdir build
cd build
```

Once you are inside of the build directory, you can run the following command to build all of the executables for the project:

```bash
cmake .. && make
```

## Testing the App

Any tests that you define in the `tests/` directory must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the corresponding test files from within the `build/` directory.

## Running the App

The `main.cpp` file at the root of the project must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the driver program from within the `build/` directory.

## Running Benchmarks

Benchmarking is provided with Catch2. You can write benchmarking assertions alongside test assertions right in your test files.

[catch2]: https://github.com/catchorg/Catch2
[cmake]: https://cmake.org/
[more-than-equations]: https://morethanequations.com/Computer-Science/Labs/You-Get-an-A