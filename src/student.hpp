#include <string>

#include <string>

class Student {
private:
    std::string first_name;
    std::string last_name;
    int ID;

public:
    Student(const std::string &first_name, const std::string &last_name, int ID);
    std::string get_first_name() const;
    std::string get_last_name() const;
    int get_ID() const;
};