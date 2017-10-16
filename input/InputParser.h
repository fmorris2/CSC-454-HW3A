//
// Created by freddy on 10/10/17.
//

#ifndef CSC_454_HW3A_INPUTPARSER_H
#define CSC_454_HW3A_INPUTPARSER_H

#include <vector>
#include <string>
using namespace std;

class InputParser {
public:
    vector<char> get_input();
private:
    vector<char> parse_input_from_string(string input);
    bool is_input_symbol(char c);
};

#endif //CSC_454_HW3A_INPUTPARSER_H
