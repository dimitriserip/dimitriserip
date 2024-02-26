
#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <cstdio>
#include <string>
#include <fstream>

#include "Professor.h"
#include "Course.h"
#include "Student.h"

using namespace std;

class Database {
public:
    Database();
    virtual ~Database();

    vector<Professor> professors;
    vector<Course> courses;
    vector<Student> students;

    void load() {
        loadProfessors();
        loadStudents();
        loadCourses();
        loadAssignments();
        loadEnrollments();
    }

    void save() {
        saveProfessors();
        saveStudents();
        saveCourses();
        saveAssignments();
        saveEnrollments();
    }
private:

    void trim(char * buffer) {
        if (strchr(buffer, '\n') != nullptr) {
            *strchr(buffer, '\n') = '\0';
        }
    }

    //
    // load
    //

    void loadProfessors() {
        char buffer[1000];
        FILE * fp = fopen("professors.csv", "rt");

        if (fgets(buffer, sizeof (buffer), fp) == NULL) {
            return;
        }

        while (true) {
            char * firstname;
            char * lastname;
            char * comskills;
            char * curiosity;
            char * experience;

            if (fgets(buffer, sizeof (buffer), fp) == NULL) {
                break;
            }

            trim(buffer);

            if (strlen(buffer) < 2) {
                continue;
            }

            firstname = strtok(buffer, ",");
            lastname = strtok(NULL, ",");
            comskills = strtok(NULL, ",");
            curiosity = strtok(NULL, ",");
            experience = strtok(NULL, ",");

            string name = string(firstname) + " " + string(lastname);

            Professor p(name, atoi(comskills), atoi(curiosity), atoi(experience));

            professors.push_back(p);
        }

        fclose(fp);
    }

    //segmentation fault in loadStudents , cant find it

    void loadStudents() {
        char buffer[1000];
        FILE * fp = fopen("students.csv", "rt");

        if (fgets(buffer, sizeof (buffer), fp) == NULL) {
            return;
        }

        while (true) {
            char * firstname;
            char * lastname;
            char * comskills;
            char * curiosity;
            char * am;

            if (fgets(buffer, sizeof (buffer), fp) == NULL) {
                break;
            }

            trim(buffer);

            if (strlen(buffer) < 2) {
                continue;
            }

            firstname = strtok(buffer, ",");
            lastname = strtok(NULL, ",");
            am = strtok(NULL, ",");
            curiosity = strtok(NULL, ",");
            comskills = strtok(NULL, ",");

            string name = string(firstname) + " " + string(lastname);

            Student s(atoi(am), name, atoi(comskills), atoi(curiosity));

            students.push_back(s);
        }

        fclose(fp);
    }

    void loadCourses() {
        char buffer[1000];
        FILE * fp = fopen("courses.csv", "rt");

        if (fgets(buffer, sizeof (buffer), fp) == NULL) {
            return;
        }

        while (true) {
            char * name;
            char * semester;
            char * optional;
            char * credits;

            if (fgets(buffer, sizeof (buffer), fp) == NULL) {
                break;
            }

            trim(buffer);

            if (strlen(buffer) < 2) {
                continue;
            }

            name = strtok(buffer, ",");
            semester = strtok(NULL, ",");
            optional = strtok(NULL, ",");
            credits = strtok(NULL, ",");


            bool optional_value = strcmp(optional, "true") == 0;

            Course c(name, atoi(credits), atoi(semester), optional_value);

            courses.push_back(c);
        }

        fclose(fp);
    }

    void loadAssignments() {
        char buffer[1000];
        FILE * fp = fopen("assignments.csv", "rt");

        if (fgets(buffer, sizeof (buffer), fp) == NULL) {
            return;
        }

        while (true) {
            char * profname;
            char * coursename;

            if (fgets(buffer, sizeof (buffer), fp) == NULL) {
                break;
            }

            trim(buffer);

            if (strlen(buffer) < 2) {
                continue;
            }

            profname = strtok(buffer, ",");
            coursename = strtok(NULL, ",");

            Professor * p = findProfessor(profname);

            Course * c = findCourse(coursename);

            if (p != nullptr && c != nullptr) {
                c->getProfessors().insert(p);
            }
        }

        fclose(fp);
    }

    void loadEnrollments() {
        char buffer[1000];
        FILE * fp = fopen("enrollments.csv", "rt");

        if (fgets(buffer, sizeof (buffer), fp) == NULL) {
            return;
        }

        while (true) {
            char * am;
            char * coursename;
            char * grade;

            if (fgets(buffer, sizeof (buffer), fp) == NULL) {
                break;
            }

            trim(buffer);

            if (strlen(buffer) < 2) {
                continue;
            }

            am = strtok(buffer, ",");
            coursename = strtok(NULL, ",");
            grade = strtok(NULL, ",");

            Student * s = findStudent(atoi(am));

            Course * c = findCourse(coursename);

            if (s != nullptr && c != nullptr) {
                s->getCourses().insert(c);
                s->getGrades()[c] = atoi(grade);
            }
        }

        fclose(fp);
    }

    //
    // load
    //

    void saveProfessors() {
        char buffer[1000];
        FILE * fp = fopen("professors.csv.saved", "wt+");

        strcpy(buffer, "FirstName,LastName,CommunicationSkills,Curiosity,ExperienceInYears\n");

        fputs(buffer, fp);

        for (Professor & p : professors) {
            strcpy(buffer, p.getName().c_str());

            char *firstname = strtok(buffer, " ");
            char *lastname = strtok(NULL, " ");

            sprintf(buffer, "%s,%s,%u,%u,%u\n", firstname, lastname, p.getCommunicationSkills(), p.getCuriosity(), p.getExperience_in_years());

            fputs(buffer, fp);
        }

        fflush(fp);
        fclose(fp);
    }

    void saveStudents() {
        char buffer[1000];
        FILE * fp = fopen("students.csv.saved", "wt+");

        strcpy(buffer, "FirstName,LastName,Am,Curiosity,CommunicationSkills\n");

        fputs(buffer, fp);

        for (Student & s : students) {
            strcpy(buffer, s.getName().c_str());

            char *firstname = strtok(buffer, " ");
            char *lastname = strtok(NULL, " ");

            sprintf(buffer, "%s,%s,%u,%u,%u\n", firstname, lastname, s.getCommunicationSkills(), s.getCuriosity(), s.getAm());

            fputs(buffer, fp);
        }

        fflush(fp);
        fclose(fp);
    }

    void saveCourses() {
        char buffer[1000];
        FILE * fp = fopen("courses.csv.saved", "wt+");

        strcpy(buffer, "CourseName,Semester,Optional,Credits\n");

        fputs(buffer, fp);

        for (Course & c : courses) {
            strcpy(buffer, c.getName().c_str());

            char *CourseName = strtok(buffer, " ");

            sprintf(buffer, "%s,%u,%d,%u\n", CourseName, c.getSemester(), c.getOptional(), c.getCredits());

            fputs(buffer, fp);
        }

        fflush(fp);
        fclose(fp);
    }

    void saveAssignments() {
        char buffer[1000];
        FILE * fp = fopen("assignments.csv.saved", "wt+");

        strcpy(buffer, "Name,CourseName\n");

        fputs(buffer, fp);

        for (Course & c : courses) {

            for (Professor * p : c.getProfessors()) {
                sprintf(buffer, "%s,%s\n", p->getName().c_str(), c.getName().c_str());

                fputs(buffer, fp);
            }
        }

        fflush(fp);
        fclose(fp);
    }

    void saveEnrollments() {
        char buffer[1000];
        FILE * fp = fopen("enrollments.csv.saved", "wt+");

        strcpy(buffer, "Am,CourseName,Grade\n");

        fputs(buffer, fp);

        for (Student & s : students) {
            for (Course * c : s.getCourses()) {
                int grade = s.getGrades()[c];

                sprintf(buffer, "%d,%s,%d\n", s.getAm(), c->getName().c_str(), grade);

                fputs(buffer, fp);
            }
        }

        fflush(fp);
        fclose(fp);
    }

    //
    // Access data
    // 
public:
    Professor * findProfessor(string name) {
        for (Professor & p : professors) {
            if (p.getName() == name) {
                return &p;
            }
        }

        return nullptr;
    }

    Course * findCourse(string name) {
        for (Course & c : courses) {
            if (c.getName() == name) {
                return &c;
            }
        }

        return nullptr;
    }
    
    Course * findCourse(string name, unsigned int semester) {
        for (Course & c : courses) {
            if (c.getName() == name && c.getSemester() == semester) {
                return &c;
            }
        }

        return nullptr;
    }

    Student * findStudent(unsigned int am) {
        for (Student & s : students) {
            if (s.getAm() == am) {
                return &s;
            }
        }

        return nullptr;
    }
};

#endif /* DATABASE_H */

