#include <iostream>
#include <string>

#include "Person.h"
#include "Secretary.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "MainMenu.h"

using namespace std;

int main(int argc, char *argv[]) {
    Database database;

    MainMenu menu(database);

    database.load();

    while (true) {
        cout << menu;

        int choice = menu.getUserChoice();

        if (!menu.applyChoice(choice)) {
            break;
        }
    }

    database.save();


    return 0;
}