
#ifndef STUDENTMANU_H
#define STUDENTMANU_H

#include <iostream>

#include "BaseMenu.h"
#include "Student.h"
#include "vector"
#include "Database.h"

using namespace std;

class StudentMenu : public BaseMenu {
public:
    StudentMenu(Database & database);
    virtual ~StudentMenu();

    virtual void print(ostream& os) const;

    bool deleteStudent(const string& studentName);

    void printAllStudents();

    vector<Student> getAllStudents() const;

    virtual bool applyChoice(int choice);

    void studentsPassedCourse(unsigned int semester, const string& nameofCourse, const string & filename);
    
    void printHappyStudents();
private:
    Database & database;

    void addStudent(const string& name) {
        unsigned int am;
        unsigned int comskills;
        unsigned int curiosity;


        cout << "Type the am of the student[example: 2200266]: ";
        cin >> am;

        cout << "Type the communication skills [1-100]: ";
        cin >> comskills;

        cout << "Type the curiosity [1-100]: ";
        cin >> curiosity;


        Student s(am, name, comskills, curiosity);

        database.students.push_back(s);
    }

    void editStudent(const string& name) {
        for (Student & s : database.students) {
            if (s.getName() == name) {
                unsigned int am;
                unsigned int comskills;
                unsigned int curiosity;

                cout << "Type the am of the student[example: 2200266]: ";
                cin >> am;

                cout << "Type the communication skills [1-100]: ";
                cin >> comskills;

                cout << "Type the curiosity [1-100]: ";
                cin >> curiosity;

                s.setCommunicationSkills(comskills);

                s.setCuriosity(curiosity);

                s.setAm(am);

                return;
            }
        }

        cout << "Student not found with such name " << endl;
    }

    Student * getStudentByName(const string& name) {
        for (Student & s : database.students) {
            if (s.getName() == name) {
                return &s;
            }
        }

        cout << "Student with such name not found" << endl;
        return nullptr;
    }

    Course * getCourseByName(const string& name) {
        for (Course & c : database.courses) {
            if (c.getName() == name) {
                return &c;
            }
        }

        cout << "Course with such name not found" << endl;
        return nullptr;

    }
};

#endif /* STUDENTMANU_H */
