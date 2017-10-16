//
// Created by freddy on 10/10/17.
//

#ifndef CSC_454_HW3A_VENDINGMACHINE_H
#define CSC_454_HW3A_VENDINGMACHINE_H
#include <vector>
#include <string>
using namespace std;
class VendingMachine {
public:
    const int COFFEE_PRICE = 100;
    void delta(vector<char> input);
    vector<string> lambda();
    string get_state();
private:
    int value = 0, nickels = 0, dimes = 0, quarters = 0;
    bool isChangePressed = false;

    vector<string> calculate_change();
    vector<string> add_coin_to_vector(string coin, int amount);

    void process_input_symbol(char symbol);
    void process_previous_state();
    void update_state_with_input(vector<char> input);
    void handle_change();
};

#endif //CSC_454_HW3A_VENDINGMACHINE_H
