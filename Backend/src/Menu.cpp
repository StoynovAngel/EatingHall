#include <iostream>
#include "Menu.h"
using namespace std;

void Menu::showMenu(int choice){
    while(choice != 0){
        cout << "1. Check profile" << endl;
        cout << "2. Check group profile" << endl;
        cout << "3. Check balance" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
    }
}