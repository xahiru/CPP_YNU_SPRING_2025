#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
private:
    std::string name;
    std::string id;
    int age;

public:
    Person(const std::string& name, const std::string& id, int age);
    virtual ~Person() = default;
    virtual void displayInfo() const;
    std::string getID() const { return id; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

#endif