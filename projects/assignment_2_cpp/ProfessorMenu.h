
#ifndef PROFESSORMENU_H
#define PROFESSORMENU_H

#include <iostream>

#include "BaseMenu.h"
#include "vector"
#include "Professor.h"
#include "Database.h"

using namespace std;

class ProfessorMenu : public BaseMenu {
public:
    ProfessorMenu(Database & database);
    virtual ~ProfessorMenu();

    virtual void print(ostream& os) const;

    bool deleteProfessor(const string& professorName);

    void printAllProfessors();
    
    void printPendingGrades(Professor * p );
    
    void printSemesterDetailsForProfessors(Professor * p );

    vector<Professor> getAllProfessors() const;

    virtual bool applyChoice(int choice);
private:
    Database & database;

    void addProfessor(const string& name) {
        unsigned int comskills;
        unsigned int curiosity;
        unsigned int experience;

        cout << "Type the communication skills [1-100]: ";
        cin >> comskills;

        cout << "Type the curiosity [1-100]: ";
        cin >> curiosity;

        cout << "Type the experience in years [1-100]: ";
        cin >> experience;

        Professor p(name, comskills, curiosity, experience);

        database.professors.push_back(p);
    }

    void editProfessor(const string& name) {
        for (Professor & p : database.professors) {
            if (p.getName() == name) {
                unsigned int comskills;
                unsigned int curiosity;
                unsigned int experience;

                cout << "Type the communication skills [1-100]: ";
                cin >> comskills;

                cout << "Type the curiosity [1-100]: ";
                cin >> curiosity;

                cout << "Type the experience in years [1-100]: ";
                cin >> experience;

                p.setCommunicationSkills(comskills);

                p.setCuriosity(curiosity);

                p.setExperience_in_years(experience);

                return;
            }
        }

        cout << "Professor not found with such name " << endl;
    }
};

#endif /* PROFESSORMENU_H */
