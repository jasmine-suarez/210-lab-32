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

    for (int i = 0; i < INITIAL_SIZE; i++) {
        Car c;
        tollLane.push_back(c);
        c.print();
    }

    cout << "Initial queue:\n";
    cout << "    ";

    return 0;
}