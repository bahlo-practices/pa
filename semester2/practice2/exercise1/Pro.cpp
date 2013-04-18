//
//  Pro.cpp
//  exercise1
//

#include <stdexcept>

#include "Pro.h"

Pro::Pro() : name(""), number(0) {};
Pro::Pro(std::string _name, int _number) : name(_name), number(_number) {};

void Pro::increase() {
    number = number + 1;
}

void Pro::print() const {
    std::cout << "Name: " << name << ", Nummer: " << number << std::endl;
}

// Getter
std::string Pro::get_name() const {
    return name;
}
int Pro::get_number() const {
    return number;
}

// Setter
void Pro::set_name(std::string _name) {
    name = _name;
}
void Pro::set_number(int _number) {
    number= _number;
}