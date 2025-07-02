#include "person.h"
#include <iostream>
Person::Person(const std::string& n, const std::string& i, int a)
    : name(n), id(i), age(a) {}

std::string Person::getID() const { return id; }
