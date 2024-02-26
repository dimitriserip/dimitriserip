#include <iostream>

#include "StudentMenu.h"
#include "MainMenu.h"
#include "string.h"
#include "Student.h"
#include "vector"
#include "Database.h"

using namespace std;

StudentMenu::StudentMenu(Database & database) : BaseMenu(0, 10), database(database) {
}

StudentMenu::~StudentMenu() {
}

void StudentMenu::print(ostream& os) const {
    os << "__________________________________________________" << endl;
    os << "                     Student Menu " << endl;
    os << "           Home -> Manage Students " << endl;
    os << "__________________________________________________" << endl;
    os << "   1. Add a student " << endl;
    os << "   2. Edit a student" << endl;
    os << "   3. Delete a student" << endl;
    os << "   4. List Students" << endl;
    os << "   5. Enroll to a course" << endl;
    os << "   6. View enrollments" << endl;
    os << "   7. View which students passed a course" << endl;
    os << "   8. View grades of a student for current semester " << endl;
    os << "   9. View grades of a student for all semesters" << endl;
    os << "   10. Happy students (can get their bachelor) " << endl;
    os << "   0. Back to main menu " << endl;
}

bool StudentMenu::deleteStudent(const string& studentName) {
    bool found = false;

    for (size_t i = 0; i < database.students.size(); ++i) {
        if (database.students[i].getName() == studentName) {
            database.students.erase(database.students.begin() + i);
            cout << "Student deleted: " << studentName << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No student with such name exists: " << studentName << endl;
    }
    return found;
}

void StudentMenu::printAllStudents() {
    cout << "All students: " << endl;
    for (size_t i = 0; i < database.students.size(); ++i) {
        database.students[i].printName();
    }
}

vector<Student> StudentMenu::getAllStudents() const {
    return database.students;
}

void StudentMenu::studentsPassedCourse(unsigned int semester, const string& nameofCourse, const string & filename) {

    Course * c1 = database.findCourse(nameofCourse, semester);

    if (c1 == nullptr) {
        cout << "Course not found" << endl;
        return;
    }

    cout << "Students that have passed: " << nameofCourse << " at semester " << semester << endl;



    char buffer[1000];
    FILE * fp = fopen(filename.c_str(), "wt+");

    strcpy(buffer, "FirstName,LastName,Am,Curiosity,CommunicationSkills\n");

    fputs(buffer, fp);

    for (Student & student : database.students) {
        for (Course * c2 : student.getCourses()) {
            if (c1 == c2 && student.getGrades()[c2] >= 5) {
                cout << student << endl;

                strcpy(buffer, student.getName().c_str());

                char *firstname = strtok(buffer, " ");
                char *lastname = strtok(NULL, " ");

                sprintf(buffer, "%s,%s,%u,%u,%u\n", firstname, lastname, student.getCommunicationSkills(), student.getCuriosity(), student.getAm());

                fputs(buffer, fp);
            }
        }
    }

    fflush(fp);
    fclose(fp);


}

void StudentMenu::printHappyStudents() {
    for (Student & s : database.students) {
        //
        // At least 4th year
        //
        unsigned int year = CURRENT_YEAR - s.getMatriculationYear() + 1;

        if (year <= 3) {
            continue;
        }

        //
        // Has passed all mandatory courses
        // 
        bool ok = true;

        for (Course & c : database.courses) {
            if (c.getOptional() == true) {
                if (s.getGrades()[&c] <= 5) {
                    ok = false;
                }
            }
        }

        if (!ok) {
            continue;
        }

        //
        // Total ECTS > 80
        //

        unsigned int total = 0;

        for (Course * c : s.getCourses()) {
            unsigned int grade = s.getGrades()[c];
            if (grade >= 5) {
                total += c->getCredits();
            }
        }

        if (total < 80) {
            continue;
        }

        char buffer[2000];

        strcpy(buffer, s.getName().c_str());

        char *firstname = strtok(buffer, " ");
        char *lastname = strtok(NULL, " ");

        sprintf(buffer, "%s,%s,%u,%u,%u\n", firstname, lastname, s.getCommunicationSkills(), s.getCuriosity(), s.getAm());

        puts(buffer);
    }
}

bool StudentMenu::applyChoice(int choice) {
    string name;
    string deleteName;
    string firstname;
    string lastname;
    string courseName;

    switch (choice) {
        case 0:
            BaseMenu::mode = MODE_MAIN_MENU;
            return true;

        case 1:
            cout << "Please enter the firstname of the student:";
            cin >> firstname;

            cout << "Please enter the lastname of the student:";
            cin >> lastname;

            name = firstname + " " + lastname;

            addStudent(name);
            return true;

        case 2:
            cout << "Please enter the firstname of the student:";
            cin >> firstname;

            cout << "Please enter the lastname of the student:";
            cin >> lastname;

            name = firstname + " " + lastname;

            editStudent(name);
            return true;

        case 3:
            cout << "Please enter the firstname of the student:";
            cin >> firstname;

            cout << "Please enter the lastname of the student:";
            cin >> lastname;

            name = firstname + " " + lastname;

            deleteStudent(name);
            return true;
        case 4:
            for (Student & s : database.students) {
                cout << s << endl;
            }
            return true;

        case 5:
        {
            cout << "Please enter the firstname of the student:";
            cin >> firstname;

            cout << "Please enter the lastname of the student:";
            cin >> lastname;

            name = firstname + " " + lastname;

            cout << "Please enter the name of the course: " << endl;
            cin >> courseName;

            Student * s = getStudentByName(name);

            Course * c = getCourseByName(courseName);

            if (s != nullptr && c != nullptr) {
                s->enrollToCourse(*c);
            }
            return true;
        }
        case 6:
        {
            for (Student & s : database.students) {
                cout << s << endl;

                for (Course * c : s.getCourses()) {
                    if (s.getGrades()[c] != -1) {
                        cout << "  - " << c->getName() << " : " << s.getGrades()[c] << endl;
                    } else {
                        cout << "  - " << c->getName() << " : not graded yet " << endl;
                    }
                }
            }
            return true;
        }
        case 7:
        {
            unsigned int givenSemester;
            string givenCourse;
            string filename;

            cout << "Please give the semester: ";
            cin >> givenSemester;

            cout << "Please give the Course: ";
            cin >> givenCourse;

            cout << "Type the file to export the data:";
            cin >> filename;

            studentsPassedCourse(givenSemester, givenCourse, filename);
            break;
        }
        case 8:
        {
            string name;
            unsigned int semester;

            cout << "Please enter the first name of the student:";
            cin >> firstname;

            cout << "Please enter the last name of the student:";
            cin >> lastname;

            name = firstname + " " + lastname;

            Student * student = getStudentByName(name);

            int year = CURRENT_YEAR - student->getMatriculationYear() + 1;

            if (CURRENT_SEASON == WINTER) {
                semester = year * 2;
            } else {
                semester = year * 2 + 1;
            }

            student->printGrades(semester);
            break;
        }
        case 9:
        {
            string name;

            cout << "Please enter the first name of the student:";
            cin >> firstname;

            cout << "Please enter the last name of the student:";
            cin >> lastname;

            name = firstname + " " + lastname;

            Student * student = getStudentByName(name);

            student->printGrades();
            break;
        }

        case 10:
            printHappyStudents();
            break;
    }

    return true;
}