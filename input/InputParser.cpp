//
// Created by freddy on 10/10/17.
//

#include "InputParser.h"
#include <iostream>

vector<char> InputParser::get_input() {
    string input;
    cout << "--> ";
    cin >> input;
    return parse_input_from_string(input);
}

vector<char> InputParser::parse_input_from_string(string input) {
    vector<char> parsed_input;
    for(char& c : input) {
        if(is_input_symbol(c)) {
            parsed_input.push_back(c);
        }
    }
    return parsed_input;
}

bool InputParser::is_input_symbol(char c) {
   switch(c) {
       case 'c':
       case 'w':
       case 'n':
       case 'd':
       case 'q':
           return true;
    }
    return false;
}

