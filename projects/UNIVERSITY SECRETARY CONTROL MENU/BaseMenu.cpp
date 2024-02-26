#include <string>

#include "BaseMenu.h"

using namespace std;

int BaseMenu::mode = MODE_MAIN_MENU;
 
BaseMenu::BaseMenu(unsigned int min_choice, unsigned int max_choice) : min_choice(min_choice), max_choice(max_choice) {
}

BaseMenu::~BaseMenu() {
}

unsigned int BaseMenu::getUserChoice() const {
    string userChoice = "";

    unsigned int value = 0;

    while (true) {
        cout << "Type your choice [" << min_choice <<"-" << max_choice << "]: ";

        getline(cin, userChoice);
        
        if (userChoice == "" || !isdigit(userChoice[0])) {
            continue;
        }

        value = atoi(userChoice.c_str());
        
        if (value < min_choice || value > max_choice) {
            cerr << "Error: Invalid choice " << endl;
        } else {
            break;
        }
    }

    return value;
}

