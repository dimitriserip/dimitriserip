#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <set>

#include "Person.h"
#include "Professor.h"

using namespace std;

class Course {
private:
    string name;
    unsigned int semester;
    bool optional;
    int credits;
    set<Professor *> professors;

public:
    Course() : semester(0), optional(true), credits(0){
        
    }
    
    Course(const string& name, int credits, unsigned int semester, bool optional = true)
    : name(name), semester(semester), optional(optional), credits(credits) {

    }

    string getName() {
        return name;
    }

    unsigned int getSemester() {
        return semester;
    }

    bool getOptional() {
        return optional;
    }

    int getCredits() {
        return credits;
    }

    void setCredits(int credits) {
        this->credits = credits;
    }

    void setName(string name) {
        this->name = name;
    }

    void setOptional(bool optional) {
        this->optional = optional;
    }

    set<Professor*> & getProfessors() {
        return professors;
    }
    
    void setProfessors(set<Professor*> & professors){
        this->professors = professors;
    }

    void setSemester(unsigned int semester) {
        if (semester > 8 || semester == 0) {
            throw out_of_range("Semester should be between 1 and 8");
        }
        
        this->semester = semester;
    }

    void printName(){
        cout << name;
    }
    
    friend ostream& operator<<(ostream& os , const Course& obj);
};
