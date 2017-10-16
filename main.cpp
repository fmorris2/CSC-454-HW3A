//
// Created by freddy on 10/10/17.
//
#include <stdio.h>
#include <iostream>
#include "vm/VendingMachine.h"
#include "input/InputParser.h"

using namespace std;
int main() {
    VendingMachine vendingMachine;
    InputParser inputParser;
    int tick = 0;
    while(true) {
        vector<char> input = inputParser.get_input();
        cout << "state at tick " << tick << ": " << vendingMachine.get_state() << endl;
        vector<string> output = vendingMachine.lambda();
        cout << "output at tick " << tick << ": " << endl;
        for(string o : output) {
            cout << o << endl;
        }

        vendingMachine.delta(input);
        tick++;
    }
}

