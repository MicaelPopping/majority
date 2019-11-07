#include "brc/brc_manager.hpp"


#include <utility>
using std::pair;
#include <iterator>
using std::iterator;

#include "brc/brc_operator/brc_operator_s1.hpp"
#include "brc/brc_operator/brc_operator_s2.hpp"
#include "brc/brc_operator/brc_operator_s3.hpp"
#include "brc/brc_operator/brc_operator_s4.hpp"
#include "brc/brc_operator/brc_operator_s5.hpp"


/************************************************************************
*                           Publics methods                             *
************************************************************************/

BRC_Manager::BRC_Manager()
: inputs_number(0), const_true(nullptr), const_false(nullptr), brc_operator(nullptr) {}

/************************************************************************/

BRC_Manager::BRC_Manager(set<string>& inputs) {

    generate_values(inputs);
}

/************************************************************************/

BRC_Manager::~BRC_Manager() {

    // IMPLEMENTAR DESTRUTOR.
}

/************************************************************************/

void BRC_Manager::insert(string input) {

    table.insert(pair<string, BR_Code*> (input, nullptr));
    inputs_number = table.size();
}

/************************************************************************/

void BRC_Manager::generate_values() {

    if(inputs_number == 0)
        return;

    initialize_operator();
    start_values();
}

/************************************************************************/

void BRC_Manager::generate_values(set<string>& inputs) {

    inputs_number = inputs.size();

    for(set<string>::iterator i = inputs.begin(); i != inputs.end(); i++) {
        table.insert(pair<string, BR_Code*> (*i, nullptr));
    }

    generate_values();
}

/************************************************************************/

BR_Code* BRC_Manager::brc_input_of(string input) {

    return table.find(input)->second;
}

/************************************************************************/

BR_Code* BRC_Manager::execute_and(BR_Code& operating_1, BR_Code& operating_2) {

    return brc_operator->execute_and(operating_1, operating_2);
}

/************************************************************************/

BR_Code* BRC_Manager::execute_or(BR_Code& operating_1, BR_Code& operating_2) {

    return brc_operator->execute_or(operating_1, operating_2);
}

/************************************************************************/

BR_Code* BRC_Manager::execute_not(BR_Code& operating_1) {

    return brc_operator->execute_not(operating_1);
}

/************************************************************************/

BR_Code* BRC_Manager::execute_maj3(BR_Code& operating_1, BR_Code& operating_2, BR_Code& operating_3) {

    return execute_maj3(operating_1, operating_2, operating_3);
}

/************************************************************************
*                         Protecteds methods                            *
************************************************************************/

/************************************************************************
*                          Privates methods                             *
************************************************************************/

void BRC_Manager::initialize_operator() {

    /*
    if(inputs_number > 5)
        brc_operator = new BRC_Operator_Long(inputs_number);
    */
    if(inputs_number == 5)
        brc_operator = new BRC_Operator_S5();

    else if(inputs_number == 4)
        brc_operator = new BRC_Operator_S4();

    else if(inputs_number == 3)
        brc_operator = new BRC_Operator_S3();
    
    else if(inputs_number == 2)
        brc_operator = new BRC_Operator_S2();

    else if(inputs_number == 1)
        brc_operator = new BRC_Operator_S1();
}

/************************************************************************/

 void BRC_Manager::start_values() {

     uint8_t level = 1;

     for(map<string, BR_Code*>::iterator i = table.begin(); i != table.end(); i++, level++)
        i->second = brc_operator->primary_value_at(level);
}

/************************************************************************
*                           Statics methods                             *
************************************************************************/