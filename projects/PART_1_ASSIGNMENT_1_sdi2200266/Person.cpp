#include <iostream>

#include "Person.h"

using namespace std;

int Person::counter = 0;

Person::Person() : name("anonymous") {
    counter++;
    communicationSkills = 50;
    curiosity = 50;
}

Person::Person(string name) : name(name) {
    counter++;
    communicationSkills = 50;
    curiosity = 25;
}

Person::Person(const Person & other) : name(other.name), communicationSkills(other.communicationSkills), curiosity(other.curiosity) {
    counter++;
}

Person::~Person() {
    counter--;
}

void Person::ask_a_question() {
    curiosity = curiosity + 5;
    communicationSkills = communicationSkills + 5;
}

void Person::setName(string newName) {
    name = newName;
}

string Person::getName() {
    return name;
}

ostream& operator<<(ostream& os, const Person& obj) {
    os << "--------------------------------------------" << endl;
    os << "Name is            : " << obj.name << endl;
    os << "Comunication skills: " << obj.communicationSkills << endl;
    os << "Curiosity          : " << obj.curiosity << endl;
    os << "Memory address     : " << &obj << endl;
    return os;
}

istream& operator>>(istream& is, Person& obj) {
    is >> obj.name;
    is >> obj.communicationSkills;
    is >> obj.curiosity;
    return is;
}

int Person::count() {
    return counter;
}

Person& Person::operator=(const Person& right) {
    if (this == &right) {
        return *this; 
    }
    
    this->name = right.name;
    this->communicationSkills = right.communicationSkills;
    this->curiosity = right.curiosity;
    
    return *this;
}