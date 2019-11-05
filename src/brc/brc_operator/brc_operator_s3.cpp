#include "brc/brc_operator/brc_operator_s3.hpp"


/************************************************************************
*                           Publics methods                             *
************************************************************************/
BRC_Operator_S3::BRC_Operator_S3() 
: BRC_Operator_Short(3) {}

/************************************************************************/

BR_Code* BRC_Operator_S3::primary_value_at(uint8_t level) {

    BR_Code* result = new BR_Code(INPUTS_NUMBER);

    if(level == 1) {

        *(result->br_code) = 0xF0;
        return result;
    }

    if(level == 2) {

        *(result->br_code) = 0xCC;
        return result;
    }

    if(level == 3) {

        *(result->br_code) = 0xAA;
        return result;
    }

    if(level == 0) {

        *(result->br_code) = 0x0;
        return result;
    }

    if(level == 100) {

        *(result->br_code) = 0xFF;
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