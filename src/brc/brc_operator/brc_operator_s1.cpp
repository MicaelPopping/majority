#include "brc/brc_operator/brc_operator_s1.hpp"


/************************************************************************
*                           Publics methods                             *
************************************************************************/
BRC_Operator_S1::BRC_Operator_S1() 
: BRC_Operator_Short(1) {}

/************************************************************************/

BR_Code* BRC_Operator_S1::primary_value_at(uint8_t level) {

    BR_Code* result = new BR_Code(INPUTS_NUMBER);

    if(level == 1) {

        *(result->br_code) = 0x2;
        return result;
    }

    if(level == 0) {

        *(result->br_code) = 0x0;
        return result;
    }

    if(level == 100) { // Arrumar depois

        *(result->br_code) = 0x3;
        return result;
    }

    delete result;
    return nullptr;
}

/************************************************************************
*                         Protecteds methods                            *
************************************************************************/

/************************************************************************
*                          Privates methods                             *
************************************************************************/

/************************************************************************
*                           Statics methods                             *
************************************************************************/