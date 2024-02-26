#pragma once

#include <iostream>
#include <fstream>

#include "Secretary.h"
#include "Person.h"

using namespace std;

class Professor : public Person {
protected:
    unsigned int experience_in_years;
public:
    Professor(): experience_in_years(0){

    }

    Professor(string name, unsigned int communicationSkills, unsigned int curiosity, unsigned int experience_in_years) 
        : Person(name, communicationSkills, curiosity), experience_in_years(experience_in_years) {
    }
        
    int getExperience_in_years() const {
        return experience_in_years;
    }

    void setExperience_in_years(int experience_in_years) {
        this->experience_in_years = experience_in_years;
    }

    void printName(){
        cout << name;
    }
    
    friend ostream& operator<<(ostream& os , const Professor& obj);
};

