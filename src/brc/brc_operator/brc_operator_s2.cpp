#include "brc/brc_operator/brc_operator_s2.hpp"


/************************************************************************
*                           Publics methods                             *
************************************************************************/

BRC_Operator_S2::BRC_Operator_S2() 
: BRC_Operator_Short(2) {}

/************************************************************************/

BR_Code* BRC_Operator_S2::primary_value_at(uint8_t level) {

    BR_Code* result = new BR_Code(INPUTS_NUMBER);

    if(level == 1) {

        *(result->br_code) = 0xC;
        return result;
    }

    if(level == 2) {

        *(result->br_code) = 0xA;
        return result;
    }

    if(level == 0) {

        *(result->br_code) = 0x0;
        return result;
    }

    if(level == 100) {

        *(result->br_code) = 0xF;
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