
#include <stdlib.h>
#include <iostream>

#include <iostream>
#include <string>

#include "Person.h"
#include "Secretary.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"

using namespace std;

void test1(){
    std::cout << "newsimpletest test 1" << std::endl;

    Person *a = new Person("jim");
    cout << Person::count() << endl;

    Person *b = new Person("tom");
    cout << Person::count() << endl;

    Person *c = new Person("eva");
    cout << Person::count() << endl;

    Person *d = new Person("mairy");
    cout << Person::count() << endl;

    Person *e = new Person(*a); // another jim
    cout << Person::count() << endl;

    Person *f = new Person("bob");
    cout << Person::count() << endl;

    Person *g = new Person();
    *g = *d; // another mairy


    cout << a->getName() << endl;

    cout << *a;
    cout << *b;
    cout << *c;
    cout << *d;

    Secretary secretary;

    secretary + a;
    secretary + b;
    secretary + c;
    secretary + d;
    secretary + e;
    secretary + g;

    cout << "*********************************************\n";
    cout << "           Secretary members: " << endl;
    cout << "*********************************************\n";
    cout << secretary;

    cout << "##########################################\n";
    cout << "Search for jim ... jim exists in collection: ";
    if (secretary.findPerson(a->getName())) {
        cout << "true \n";
    } else {
        cout << "false \n";
    }

    cout << "Search for Bob ... Bob exists in collection: ";
    if (secretary.findPerson(f->getName())) {
        cout << "true \n";
    } else {
        cout << "false \n";
    }


    Secretary secretaryCopy = secretary;

    cout << "*********************************************\n";
    cout << "           Secretary copy / members: " << endl;
    cout << "*********************************************\n";
    cout << secretaryCopy;

    cout << "*********************************************\n";
    cout << "         Enter Secretary members: " << endl;
    cout << "*********************************************\n";

    cin >> secretary;

    cout << "*********************************************\n";
    cout << "           Secretary members (after input): " << endl;
    cout << "*********************************************\n";
    cout << secretary;



    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
}


void test2() {
    std::cout << "newsimpletest test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (newsimpletest) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (newsimpletest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

