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

    return 0;
}