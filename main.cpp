#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();




    return 0;
}

int main_menu() {
    char choice;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;
    return choice;
}

int select_goat(list<Goat> trip) {
    if (trip.empty()) {
        cout << "Nothing selected" << endl;
        return;
    }

    int num = 1;
    cout << "Select a goat:" << endl;
    for (const auto &goat : trip) {
        cout << "[" << num << "]" << goat.get_name() << " (" << goat.get_age()
            << ", " << goat.get_color() << ")" << endl;
        num++;
    }

    int choice;
    cin >> choice;
}

void delete_goat(list<Goat> &trip) {

}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    int random_name = rand() % SZ_NAMES;
    int random_color = rand() % SZ_COLORS;
    int random_age = rand() % MAX_AGE;

    Goat new_goat(names[random_name], random_age, colors[random_color]);
    trip.push_back(new_goat);

    cout << "Added: " << new_goat.get_name() << " (" << new_goat.get_age()
        << ", " << new_goat.get_color() << ")" << endl;
}

void display_trip(list<Goat> trip) {
    if (trip.empty()) {
        cout << "Empty list" << endl;
        return;
    }
    
    for (const auto &goat : trip) {
        cout << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
    }
}
