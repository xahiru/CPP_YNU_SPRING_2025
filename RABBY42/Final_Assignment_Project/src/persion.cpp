#include "../include/person.h"
#include <iostream>

Person::Person(const std::string& name, const std::string& id, int age)
    : name(name), id(id), age(age) {}

void Person::displayInfo() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Age: " << age;
}