#include <iostream>
using std::cout;
using std::endl;

#include "brc/brc_manager.hpp"


int main(int argc, char **argv) {

    cout << "Majority" << endl;
    BRC_Manager brc;

    brc.insert("x1");
    brc.insert("x2");
    brc.insert("x3");

    brc.generate_values();
    
    return 0;
}