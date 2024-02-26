#pragma once

#include <iostream>
#include <string>

using namespace std;




class Person{
protected:
    string name;
    static int counter;
    unsigned int communicationSkills;        //from 1-100
    unsigned int curiosity;                  //from 1-100
public:
    Person();
        
    Person(string name);
    
    Person(const Person & other);
    
    Person(string name, unsigned int communicationSkills, unsigned int curiosity);
    
    ~Person();

    string getName() const;

    void ask_a_question();

    void setName(string newName);
    
    static int getCounter() {
        return counter;
    }
    
    unsigned int getCommunicationSkills() const {
        return communicationSkills;
    }

    unsigned int getCuriosity() const {
        return curiosity;
    }

    void setCommunicationSkills(unsigned int communicationSkills) {
        this->communicationSkills = communicationSkills;
    }

    void setCuriosity(unsigned int curiosity) {
        this->curiosity = curiosity;
    }

    
    Person& operator=(const Person& right);


    friend ostream& operator<<(ostream& os , const Person& obj);

    friend istream& operator>>(istream& is , Person& obj);
    
    static unsigned int count();

};
