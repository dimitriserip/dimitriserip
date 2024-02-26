#include <iostream>

#include "Person.h"
#include "Secretary.h"

using namespace std;

// T x(y); // copy c-tor
// T x = y; // copy c-tor
// T x; //  default c-tor
// x = y; operator =

int main(int argc, char *argv[]) {
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

    return 0;
}