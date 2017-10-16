//
// Created by freddy on 10/10/17.
//
#include "VendingMachine.h"
#include <iostream>

vector<string> VendingMachine::lambda() {
    vector<string> output;
    if(isChangePressed && value > 0) {
        vector<string> change = calculate_change();
        output.insert(output.end(), change.begin(), change.end());
    } else if(value >= COFFEE_PRICE) {
        int num_coffees = value / COFFEE_PRICE;
        output.push_back(to_string(num_coffees) + " x coffee");
    } else {
        output.push_back("nothing");
    }

    return output;
}

vector<string> VendingMachine::calculate_change() {
    vector<string> change;
    int change_needed = value;
    if(quarters > 0 && change_needed >= 25) {
        vector<string> quarters = add_coin_to_vector("quarter", change_needed / 25);
        change.insert(change.begin(), quarters.begin(), quarters.end());
        change_needed %= 25;
    }
    if(dimes > 0 && change_needed >= 10) {
        vector<string> dimes = add_coin_to_vector("dime", change_needed / 10);
        change.insert(change.begin(), dimes.begin(), dimes.end());
        change_needed %= 10;
    }
    if(nickels > 0 && change_needed >= 5) {
        vector<string> nickels = add_coin_to_vector("nickel", change_needed / 5);
        change.insert(change.begin(), nickels.begin(), nickels.end());
        change_needed %= 5;
    }
    if(change_needed > 0) {
        cout << "COULD NOT PRODUCE ENOUGH CHANGE!" << endl;
    }

    return change;
}

vector<string> VendingMachine::add_coin_to_vector(string coin, int amount) {
    vector<string> list;
    for(int i = 0; i < amount; i++) {
        list.push_back(coin);
    }
    return list;
}

void VendingMachine::delta(vector<char> input) {
    process_previous_state();
    update_state_with_input(input);
}

void VendingMachine::process_previous_state() {
    if(isChangePressed) {
        handle_change();
    }
    else if(value >= COFFEE_PRICE){
        value %= COFFEE_PRICE;
    }
}

void VendingMachine::handle_change() {
    vector<string> change = calculate_change();
    for(string coin : change) {
        if(coin.compare("nickel") == 0) {
            nickels--;
            value -= 5;
        } else if(coin.compare("dime") == 0) {
            dimes--;
            value -= 10;
        } else if(coin.compare("quarter") == 0) {
            quarters--;
            value -= 25;
        }
    }

    isChangePressed = false;
}

void VendingMachine::update_state_with_input(vector<char> input) {
    for(char& c : input) {
        process_input_symbol(c);
    }
}

void VendingMachine::process_input_symbol(char symbol) {
    switch(symbol) {
        case 'c':
            isChangePressed = true;
            break;
        case 'n':
            nickels++;
            value += 5;
            break;
        case 'd':
            dimes++;
            value += 10;
            break;
        case 'q':
            quarters++;
            value += 25;
            break;
    }
}

string VendingMachine::get_state() {
    return "v: " + to_string(value) + ", c: " + to_string(isChangePressed)
           + ", n: " + to_string(nickels) + ", d: " + to_string(dimes)
           + ", q: " + to_string(quarters);
}

