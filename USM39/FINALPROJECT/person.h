#pragma once
#include <string>
class Person {
protected:
    std::string name, id;
    int age;
public:
    Person(const std::string& n, const std::string& i, int a);
    virtual void display() const = 0;
    std::string getID() const;
    virtual ~Person() {}
};
