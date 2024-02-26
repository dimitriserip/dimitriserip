#pragma once

#include <iostream>
#include <string>

using namespace std;


class Person{
private:
    string name;
    static int counter;
    int communicationSkills;        //from 1-100
    int curiosity;                  //from 1-100
    
public:
    Person();
        
    Person(string name);
    
    Person(const Person & other);
    

    ~Person();

    string getName();

    void ask_a_question();

    void setName(string newName);
    
    static int getCounter() {
        return counter;
    }
    
    Person& operator=(const Person& right);


    friend ostream& operator<<(ostream& os , const Person& obj);

    friend istream& operator>>(istream& is , Person& obj);
    
    static int count();

};
