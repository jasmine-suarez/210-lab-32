// COMSC-210 | Lab 32 | Jasmine Suarez
// IDE used: VS Code

#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int INITIAL_SIZE = 2; // initial size of deque when simulation starts

int main() {
    srand(time(0));

    deque<Car> tollLane;

    cout << "Initial queue:\n";
    for (int i = 0; i < INITIAL_SIZE; i++) {
        Car c;
        tollLane.push_back(c);
        cout << "    ";
        c.print();
    }
    cout << endl;

    return 0;
}