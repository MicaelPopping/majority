#include <iostream>
using std::cout;
using std::endl;

#include "brc/brc_manager.hpp"


int main(int argc, char **argv) {

    BRC_Manager brc;
    BR_Code* code;

    cout << "\nMajority\n" << endl;

    brc.insert("x1");
    brc.insert("x2");
    brc.insert("x3");
    brc.insert("x4");
    //brc.insert("x5");

    brc.generate_values();

    cout << "x1: " << brc.brc_input_of("x1")->br_code[0] << endl;
    cout << "x2: " << brc.brc_input_of("x2")->br_code[0] << endl;
    cout << "x3: " << brc.brc_input_of("x3")->br_code[0] << endl;
    cout << "x4: " << brc.brc_input_of("x4")->br_code[0] << endl;
    //cout << "x5: " << brc.brc_input_of("x5")->br_code[0] << endl;

    cout << endl;

    code = brc.execute_and(*brc.brc_input_of("x1"), *brc.brc_input_of("x2"));
    cout << "x1 * x2: " << code->br_code[0] << endl;
    delete code;
    
    code = brc.execute_not(*brc.brc_input_of("x3"));
    cout << "!x3: " << code->br_code[0] << endl;
    delete code;

    return 0;
}