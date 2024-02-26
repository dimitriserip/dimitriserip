#include <iostream>

#include "Student.h"

using namespace std;


ostream& operator<<(ostream& os, const Student& obj) {
    os << "--------------------------------------------" << endl;
    os << "Student AM         : " << obj.am << endl;
    os << "Name is            : " << obj.name << endl;
    os << "Comunication skills: " << obj.communicationSkills << endl;
    os << "Curiosity          : " << obj.curiosity << endl;
    os << "Memory address     : " << &obj << endl;
    return os;
}
