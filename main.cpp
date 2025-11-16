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
const int PAY_PROB = 46;    // 46% probability
const int JOIN_PROB = 39;   // 39% probability
const int SHIFT_PROB = 15;  // 15% probability

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

        // for-loop to go through each lane
        for (int j = 0; j < NUM_LANES; j++) {
            cout << "Lane: " << j + 1 << " ";

            // if lane is empty, 50/50 if a new car enters or not
            if (tollLanes[j].empty()) {
                if (rand() % 2 == 0) {
                    Car newCar;
                    tollLanes[j].push_back(newCar);
                    cout << "Joined: ";
                    newCar.print();
                    // cout << endl;
                }
                else
                    cout << "No event" << endl;
            }
            else {
                int r = rand() % 100; // randomizes int from 1-100

                if (r < PAY_PROB) { // car pays and leaves
                    Car leaving = tollLanes[j].front();
                    tollLanes[j].pop_front();
                    cout << "Paid: ";
                    leaving.print();
                }
                else if (r < (PAY_PROB + JOIN_PROB)) { // car joins
                    Car newCar;
                    tollLanes[j].push_back(newCar);
                    cout << "Joined: ";
                    newCar.print();
                }
                else { // rear car shifts lanes
                    int randLane = j;
                    while (randLane == j)
                        randLane = rand() % NUM_LANES;

                    Car shifting = tollLanes[j].back();
                    tollLanes[j].pop_back();
                    tollLanes[randLane].push_back(shifting);
                    cout << "Switched: ";
                    shifting.print();
                }
            }
        }

        for (int lane = 0; lane < NUM_LANES; lane++) {
            cout << "Lane " << lane + 1 << " Queue:\n";
            if (tollLanes[lane].empty())
                cout << "    Empty\n";
            else {
                for (Car &c : tollLanes[lane]) {
                    cout << "        ";
                    c.print();
                }
            }
        }
        cout << endl;
    }

    return 0;
}