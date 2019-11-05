#include "brc/brc_operator/brc_operator_s4.hpp"


/************************************************************************
*                           Publics methods                             *
************************************************************************/

BRC_Operator_S4::BRC_Operator_S4() 
: BRC_Operator_Short(4) {}

/************************************************************************/

BR_Code* BRC_Operator_S4::primary_value_at(uint8_t level) {

    BR_Code* result = new BR_Code(INPUTS_NUMBER);

    if(level == 1) {

        *(result->br_code) = 0xFF00;
        return result;
    }

    if(level == 2) {

        *(result->br_code) = 0xF0F0;
        return result;
    }

    if(level == 3) {

        *(result->br_code) = 0xCCCC;
        return result;
    }

    if(level == 4) {

        *(result->br_code) = 0xAAAA;
        return result;
    }

    if(level == 0) {

        *(result->br_code) = 0x0;
        return result;
    }

    if(level == 100) {

        *(result->br_code) = 0xFFFF;
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