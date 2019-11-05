#include "brc/brc_operator/brc_operator_s5.hpp"


/************************************************************************
*                           Publics methods                             *
************************************************************************/

BRC_Operator_S5::BRC_Operator_S5() 
: BRC_Operator_Short(5) {}

/************************************************************************/

BR_Code* BRC_Operator_S5::primary_value_at(uint8_t level) {

    BR_Code* result = new BR_Code(INPUTS_NUMBER);

    if(level == 1) {

        *(result->br_code) = 0xFFFF0000;
        return result;
    }

    if(level == 2) {

        *(result->br_code) = 0xFF00FF00;
        return result;
    }

    if(level == 3) {

        *(result->br_code) = 0xF0F0F0F0;
        return result;
    }

    if(level == 4) {

        *(result->br_code) = 0xCCCCCCCC;
        return result;
    }

    if(level == 5) {

        *(result->br_code) = 0xAAAAAAAA;
        return result;
    }

    if(level == 0) {

        *(result->br_code) = 0x0;
        return result;
    }

    if(level == 100) {

        *(result->br_code) = 0xFFFFFFFF;
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