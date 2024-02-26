#pragma once

#include <string>
#include <cstring>
#include "Person.h"

class Secretary {
private:
    Person **department;
    int numOfPeople;

public:
    Secretary();

    ~Secretary();
    
    Secretary(const Secretary& other);

    int getNumOfPeople() const;

    Person** getDepartment() const;

    Secretary &operator+(Person *person);
    
    Secretary& operator=(const Secretary& right);

    friend std::ostream &operator<<(std::ostream &os, const Secretary &secretary);

    friend std::istream& operator>>(std::istream& is, Secretary& secretary);


    bool findPerson(string name);

};
