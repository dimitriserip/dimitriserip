#include <iostream>

#include "CourseMenu.h"
#include "MainMenu.h"
#include "string.h"
#include "Course.h"
#include "vector"
#include "Professor.h"
#include "ProfessorMenu.h"

using namespace std;

CourseMenu::CourseMenu(Database & database) : BaseMenu(0, 6), database(database) {
}

CourseMenu::~CourseMenu() {
}

void CourseMenu::print(ostream& os) const {
    os << "__________________________________________________" << endl;
    os << "                     Course Menu " << endl;
    os << "           Home -> Manage Courses " << endl;
    os << "__________________________________________________" << endl;
    os << "   1. Add a course " << endl;
    os << "   2. Edit a course" << endl;
    os << "   3. Delete a course" << endl;
    os << "   4. List courses" << endl;
    os << "   5. Assign professor to a course" << endl;
    os << "   6. Remove professor from a course" << endl;
    os << "   0. Back to main menu " << endl;
}

void CourseMenu::assignProfessorToCourse() {
    int professorChoice;
    int courseChoice;
    int counter = 0;

    for (Professor & p : database.professors) {
        cout << counter << " " << p.getName() << endl;
        counter++;
    }

    cout << "Choose a professor (type the number): ";
    cin >> professorChoice;

    counter = 0;

    for (Course & c : database.courses) {
        cout << counter << " " << c.getName() << endl;
        counter++;
    }

    cout << "Choose a course to set a Professor (type the number): ";
    cin >> courseChoice;

    Professor * professor = &database.professors[professorChoice];
    Course & courseToSet = database.courses[courseChoice];

    courseToSet.getProfessors().insert(professor);
}

void CourseMenu::unassignProfessorToCourse() {
    int professorChoice;
    int courseChoice;
    int counter = 0;

    for (Professor & p : database.professors) {
        cout << counter << " " << p.getName() << endl;
        counter++;
    }

    cout << "Choose a professor (type the number): ";
    cin >> professorChoice;

    counter = 0;

    for (Course & c : database.courses) {
        cout << counter << " " << c.getName() << endl;
        counter++;
    }

    cout << "Choose a course to set a Professor (type the number): ";
    cin >> courseChoice;

    Professor * professor = &database.professors[professorChoice];
    Course & courseToSet = database.courses[courseChoice];

    courseToSet.getProfessors().erase(professor);
}

bool CourseMenu::applyChoice(int choice) {
    string name;
    string deleteName;
    string firstname, lastname;

    switch (choice) {
        case 0:
            BaseMenu::mode = MODE_MAIN_MENU;
            return true;

        case 1:
            cout << "Please enter the name of the course: " << endl;
            cin >> name;
            addCourse(name);
            return true;

        case 2:
            cout << "Please enter the course name: ";
            cin >> name;

            editCourse(name);

            return true;

        case 3:
            cout << "Please enter the name of the course to delete: " << endl;
            cin >> deleteName;
            deleteCourse(deleteName);
            return true;
        case 4:
            for (Course & c : database.courses) {
                cout << c << endl;
            }
            return true;
        case 5:
            assignProfessorToCourse();
            return true;
        case 6:
            unassignProfessorToCourse();
            return true;
    }

    return true;
}