#include <iostream>

#include "ProfessorMenu.h"
#include "MainMenu.h"
#include "string.h"
#include "vector"
#include "Student.h"
#include "Database.h"

using namespace std;

ProfessorMenu::ProfessorMenu(Database & database) : BaseMenu(0, 7), database(database) {
}

ProfessorMenu::~ProfessorMenu() {
}

void ProfessorMenu::print(ostream& os) const {

    os << "__________________________________________________" << endl;
    os << "                     Professor Menu " << endl;
    os << "           Home -> Manage Professors " << endl;
    os << "__________________________________________________" << endl;
    os << "   1. Add a professors " << endl;
    os << "   2. Edit a professor" << endl;
    os << "   3. Delete a professor" << endl;
    os << "   4. List professors" << endl;
    os << "   5. Statistics for a semester " << endl;
    os << "   6. Pending grades for a professor " << endl;
    os << "   7. Grade a student (for a professor) " << endl;
    os << "   0. Back to main menu " << endl;
}

bool ProfessorMenu::deleteProfessor(const string& professorName) {
    bool found = false;

    for (size_t i = 0; i < database.professors.size(); ++i) {
        if (database.professors[i].getName() == professorName) {
            database.professors.erase(database.professors.begin() + i);
            cout << "Professor deleted: " << professorName << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No Professor with such name exists: " << professorName << endl;
    }
    return found;
}

void ProfessorMenu::printAllProfessors() {
    cout << "All professors: " << endl;
    for (size_t i = 0; i < database.professors.size(); ++i) {
        database.professors[i].printName();
    }
}

void ProfessorMenu::printSemesterDetailsForProfessors(Professor * p1) {
    for (Course & c1 : database.courses) {
        if (CURRENT_SEASON == WINTER) {
            if (c1.getSemester() != 1 && c1.getSemester() != 3 && c1.getSemester() != 5 && c1.getSemester() != 7) {
                continue;
            }
        } else if (CURRENT_SEASON == SUMMER) {
            if (c1.getSemester() != 2 && c1.getSemester() != 4 && c1.getSemester() != 6 && c1.getSemester() != 8) {
                continue;
            }
        }

        for (Professor * p2 : c1.getProfessors()) {
            if (p1 == p2) {
                for (Student & s : database.students) {
                    for (Course * c2 : s.getCourses()) {
                        if (c2 == &c1) {
                            if (s.getGrades()[c2] != -1) {
                                cout << "  - " << c2->getName() << " : " << s.getName() << " " << s.getAm() << " : " << s.getGrades()[c2] << endl;
                            } else {
                                cout << "  - " << c2->getName() << " : " << s.getName() << " " << s.getAm() << " : " << " not graded yet " << endl;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

void ProfessorMenu::printPendingGrades(Professor * p1) {
    for (Course & c1 : database.courses) {
        for (Professor * p2 : c1.getProfessors()) {
            if (p1 == p2) {
                for (Student & s : database.students) {
                    for (Course * c2 : s.getCourses()) {
                        if (c2 == &c1) {
                            if (s.getGrades()[c2] == -1) {
                                cout << "  - " << c2->getName() << s.getName() << " " << s.getAm() << " : " << " : not graded yet " << endl;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

vector<Professor> ProfessorMenu::getAllProfessors() const {
    return database.professors;
}

bool ProfessorMenu::applyChoice(int choice) {
    string name;
    string deleteName;
    string firstname;
    string lastname;

    switch (choice) {
        case 0:
            BaseMenu::mode = MODE_MAIN_MENU;
            return true;

        case 1:
            cout << "Please enter the firstname of the professor:";
            cin >> firstname;

            cout << "Please enter the lastname of the professor:";
            cin >> lastname;

            name = firstname + " " + lastname;

            addProfessor(name);
            return true;
        case 2:
            cout << "Please enter the firstname of the professor:";
            cin >> firstname;

            cout << "Please enter the lastname of the professor:";
            cin >> lastname;

            name = firstname + " " + lastname;

            editProfessor(name);
            return true;
        case 3:
            cout << "Please enter the firstname of the professor:";
            cin >> firstname;

            cout << "Please enter the lastname of the professor:";
            cin >> lastname;

            name = firstname + " " + lastname;

            deleteProfessor(name);
            return true;
        case 4:
            for (Professor & p : database.professors) {
                cout << p << endl;
            }
            return true;
        case 5:
        {
            cout << "Please enter the firstname of the professor:";
            cin >> firstname;

            cout << "Please enter the lastname of the professor:";
            cin >> lastname;

            name = firstname + " " + lastname;

            Professor * p = database.findProfessor(name);

            if (p == nullptr) {
                cerr << "Professor not found" << endl;
            } else {
                printSemesterDetailsForProfessors(p);
            }
            return true;
        }
        case 6:
        {
            cout << "Please enter the firstname of the professor:";
            cin >> firstname;

            cout << "Please enter the lastname of the professor:";
            cin >> lastname;

            name = firstname + " " + lastname;

            Professor * p = database.findProfessor(name);

            if (p == nullptr) {
                cerr << "Professor not found" << endl;
            } else {
                printPendingGrades(p);
            }
            return true;
        }
        case 7:
        {
            string am;
            int grade;
            
            cout << "Please enter the first name of the professor:";
            cin >> firstname;

            cout << "Please enter the last name of the professor:";
            cin >> lastname;

            name = firstname + " " + lastname;

            Professor * p = database.findProfessor(name);

            if (p == nullptr) {
                cerr << "Professor not found" << endl;
                return true;
            }
            
            cout << "Type the course name:" << endl;
            cin >> name;
            
            Course * c = database.findCourse(name);
            
            if (c == nullptr) {
                cerr << "Course not found" << endl;
                return true;
            }
            
            cout << "Please enter the AM of the student:";
            cin >> am;

            Student * s = database.findStudent(atoi(am.c_str()));
            
            if (s == nullptr) {
                cerr << "Student not found" << endl;
                return true;
            }
            
            cout << "Type the grade: " << endl;
            
            cin >> grade;
            
            if (s->getGrades()[c] > 0) {
                cerr << "This student has already been graded " << endl;
                return true;
            }
            
            s->getGrades()[c] = grade;
            return true;
        }
    }

    return true;
}