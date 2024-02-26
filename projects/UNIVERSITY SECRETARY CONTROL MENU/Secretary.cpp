#include "Secretary.h"

Secretary::Secretary() : department(nullptr), numOfPeople(0) {
}

Secretary::~Secretary() {
    if (department != nullptr) {
        delete[] department;
    }
}

Secretary::Secretary(const Secretary& other) : department(other.department), numOfPeople(other.numOfPeople) {
    department = new Person*[other.numOfPeople];

    for (int i = 0; i < numOfPeople; ++i) {
        this->department[i] = other.department[i];
    }
}

int Secretary::getNumOfPeople() const {
    return numOfPeople;
}

Person** Secretary::getDepartment() const {
    return department;
}

Secretary& Secretary::operator=(const Secretary& other) {
    if (this == &other) {
        return *this;
    }

    if (department != nullptr) {
        delete[] department;
    }

    department = new Person*[other.numOfPeople];

    for (int i = 0; i < numOfPeople; ++i) {
        this->department[i] = other.department[i];
    }
    
    this->numOfPeople = other.numOfPeople;

    return *this;
}

// Secretary & Secretary::operator+(Person * person) {
//     Person** temp = new Person*[numOfPeople + 1];

//     for (int i = 0; i < numOfPeople; ++i) {
//         temp[i] = department[i];
//     }
//     temp[numOfPeople] = person;

//     if (department) {
//         delete[] department;
//     }
//     department = temp;
//     ++numOfPeople;
//     return *this;
// }

Secretary& Secretary::operator+(Person * person) {
    int newSize = (numOfPeople + 1) * 2;
    Person** temp = new Person*[newSize];

    for (int i = 0; i < numOfPeople; ++i) {
        temp[i] = department[i];

    }
    temp[numOfPeople] = person;
    
    if (department) {
        delete[] department;
    }

    department = temp;
    ++numOfPeople;
    return *this;
}


std::ostream & operator<<(std::ostream &os, const Secretary &secretary) {
    os << "Number of people is :" << secretary.numOfPeople << endl;
    for (int i = 0; i < secretary.numOfPeople; ++i) {
        cout << *secretary.department[i] << endl;

    }
    return os;
}

//
// NOT DONE YET 
//
std::istream & operator>>(std::istream &is, Secretary &secretary) {
    for (int i = 0; i < secretary.getNumOfPeople(); ++i) {
        secretary.getDepartment()[i] = new Person();
        is >> *secretary.getDepartment()[i];
    }

    return is;
}
//
// NOT DONE YET 
//

bool Secretary::findPerson(string name) {
    for (int i = 0; i < numOfPeople; ++i) {
        if (department[i]->getName() == name) {
            return true;
        }
    }
    return false;
}
