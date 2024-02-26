#include <iostream>

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu(Database & database) : BaseMenu(0, 3), database(database), professorMenu(database), studentMenu(database), courseMenu(database) {
}

MainMenu::~MainMenu() {
}

void MainMenu::print(ostream& os) const {
    os << "__________________________________________________" << endl;
    os << "                     Main Menu " << endl;
    os << "           Home" << endl;
    os << "__________________________________________________" << endl;

    os << "   1. Manage professors " << endl;
    os << "   2. Manage students " << endl;
    os << "   3. Manage courses " << endl;
    os << "   0. Exit " << endl;
}

unsigned int MainMenu::getUserChoice() const {
    switch (BaseMenu::mode) {
        case MODE_MAIN_MENU:
            return BaseMenu::getUserChoice();
        case MODE_PROFESSOR_MENU:
            return professorMenu.getUserChoice();
        case MODE_STUDENT_MENU:
            return studentMenu.getUserChoice();
        case MODE_COURSE_MENU:
            return courseMenu.getUserChoice();
    }

    throw invalid_argument("Invalid menu choice");
}

bool MainMenu::applyChoice(int choice) {
    switch (BaseMenu::mode) {
        case MODE_MAIN_MENU:
            switch (choice) {
                case 0:
                    return false;
                case 1:
                    mode = MODE_PROFESSOR_MENU;
                    return true;
                case 2:
                    mode = MODE_STUDENT_MENU;
                    return true;
                case 3:
                    mode = MODE_COURSE_MENU;
                    return true;
            }

        case MODE_PROFESSOR_MENU:
            return professorMenu.applyChoice(choice);

        case MODE_STUDENT_MENU:
            return studentMenu.applyChoice(choice);

        case MODE_COURSE_MENU:
            return courseMenu.applyChoice(choice);

    }

    return true;
}

ostream& operator<<(ostream& os, const MainMenu& menu) {
    switch (menu.mode) {
        case MODE_MAIN_MENU:
            menu.print(os);
            break;
        case MODE_PROFESSOR_MENU:
            menu.professorMenu.print(os);
            break;
        case MODE_STUDENT_MENU:
            menu.studentMenu.print(os);
            break;
        case MODE_COURSE_MENU:
            menu.courseMenu.print(os);
    }

    return os;
}
