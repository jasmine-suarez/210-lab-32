// COMSC-210 | Lab 32 | Jasmine Suarez
// IDE used: VS Code

#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int NUM_LANES = 4;    // number of toll booth lanes at play
const int INITIAL_SIZE = 2; // initial size of deque when simulation starts

int main() {
    srand(time(0));

    deque<Car> tollLanes[NUM_LANES];

    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":\n";
        for (int j = 0; j < INITIAL_SIZE; j++) {
            Car c;
            tollLanes[i].push_back(c);
            cout << "    ";
            c.print();
        }
    }
    cout << endl;

    for (int i = 1; i <= 20; i++) {   // run for 20 time periods
        cout << "Time: " << i << endl;

        //
    }

/*
    for (int i = 1; !tollLane.empty(); i++) {
        int r = rand() % 100;

        if (r < 55) { // 55% probability that the head car pays and leaves
            Car leaving = tollLane.front();
            tollLane.pop_front();
            cout << "Time: " << i << " Operation: Car paid: ";
            leaving.print();
        }
        else { // 45% probability that another car joins the line
            Car joining;
            tollLane.push_back(joining);
            cout << "Time: " << i << " Operation: Joined lane: ";
            joining.print();
        }

        cout << "Queue:\n";
        if (tollLane.empty())
            cout << "    Empty\n";
        else {
            for (Car &c : tollLane) {
                cout << "    ";
                c.print();
            }
        }
        cout << endl;
    }
*/

    return 0;
}