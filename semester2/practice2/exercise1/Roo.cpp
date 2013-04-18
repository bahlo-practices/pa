//
//  Roo.cpp
//  exercise1
//

#include "Roo.h"

Roo::Roo() : password(""), secret("") {};
Roo::Roo(std::string _password, std::string _secret) : password(_password), secret(_secret) {};

void Roo::print() const {
    std::cout << "Passwort: " << password << ", Secret: " << secret << std::endl;
}

// Getter
std::string Roo::get_secret(std::string _password) const {
    if(_password == password) {
        return secret;
    } else {
        return "";
    }
}

// Setter
void Roo::set_password(std::string _password) {
    password = _password;
}
void Roo::set_secret(std::string _secret) {
    secret = _secret;
}