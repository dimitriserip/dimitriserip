#pragma once

#include <set>
#include <map>
#include <iostream>

#include "Course.h"
#include "Secretary.h"
#include "Person.h"
#include "constants.h"

using namespace std;

class Student : public Person {
protected:
    unsigned int am;

    // Courses that the user has enrolled
    set<Course *> courses;

    // Grades for each course
    map<Course *, int> grades; // course-grade
public:

    Student(string name) : Person(name) {

    }

    Student(unsigned int am, string name, unsigned int communicationSkills, unsigned int curiosity) :
    Person(name, communicationSkills, curiosity), am(am) {
    }

    unsigned int getAm() const {
        return am;
    }

    void setAm(unsigned int am) {
        this->am = am;
    }

    set<Course *>& getCourses() {
        return courses;
    }

    void setCourses(set<Course *>& courses) {
        this->courses = courses;
    }

    map<Course *, int> & getGrades() {
        return grades;
    }

    void setGrades(map<Course *, int> & getGrades) {
        this->grades = grades;
    }

    void printName() {
        cout << name;
    }

    int getMatriculationYear() {
        char buffer[100];
        sprintf(buffer, "%d", am);

        if (strlen(buffer) > 3) {
            buffer[2] = '\0';
        }

        return atoi(buffer);
    }

    void enrollToCourse(Course & course) {

        if (courses.count(&course) > 0) {
            cout << "Student is already in this course" << endl;
        } else {
            int matriculationYear = getMatriculationYear();

            int studentYear = CURRENT_YEAR - matriculationYear; // 0,1,2,3

            int semester = course.getSemester();

            if (semester > (studentYear + 1)*2) {
                cerr << "You cannot enroll to this course yet unless you are a genius \n";
                return;
            }

            courses.insert(&course);
            grades[&course] = -1;

            cout << "Student succesfully enrolled to the course" << endl;
        }
    }

    void deleteFromCourse(Course & course) {
        Course * courseToDelete;
        auto i = courses.find(courseToDelete);

        if (i != courses.end()) {
            courses.erase(i);
            delete courseToDelete;

            grades.erase(&course);

            cout << "Course deleted successfully" << endl;
        } else {
            cout << "Student is not in this course" << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const Student& obj);

    void printGrades() {
        bool hasGrades = false;

        cout << "Grades of student " << getName() << " are: " << endl;

        for (Course * course : courses) {
            int grade = grades[course];
            
            if (grade > 0) {
                cout << "Course: " << course->getName() << ", Grade: " << grades.at(course) << endl;
                hasGrades = true;
            } else {
                cout << "Course: " << course->getName() << ", Grade: Not Graded Yet" << endl;
            }
        }

        if (!hasGrades) {
            cout << "No grades" << endl;
        }
    }
    
    void printGrades(unsigned int semester) {
        bool hasGrades = false;

        cout << "Grades of student " << getName() << " are: " << endl;

        for (Course * course : courses) {
            if (course->getSemester() != semester) {
                continue;
            }
            
            int grade = grades[course];
            
            if (grade > 0) {
                cout << "Course: " << course->getName() << ", Grade: " << grades.at(course) << endl;
                hasGrades = true;
            } else {
                cout << "Course: " << course->getName() << ", Grade: Not Graded Yet" << endl;
            }
        }

        if (!hasGrades) {
            cout << "No grades" << endl;
        }
    }
};