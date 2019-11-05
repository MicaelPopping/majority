#include "brc/brc_operator/brc_operator_short.hpp"


#include <cmath>


/************************************************************************
*                           Publics methods                             *
************************************************************************/

BRC_Operator_Short::BRC_Operator_Short(uint8_t inputs_number) 
: BRC_Operator(inputs_number, 1) {}

/***********************************************************************/

BRC_Operator_Short::~BRC_Operator_Short() {}

/***********************************************************************/

BR_Code* BRC_Operator_Short::execute_not(BR_Code& operating_1) {

    if(!(operating_1.INPUTS_NUMBER == INPUTS_NUMBER))
        return nullptr;

    BR_Code* result = new BR_Code(INPUTS_NUMBER);
    uint32_t number_of_rows =  1 << INPUTS_NUMBER;
    char number_bin[number_of_rows];

    convert_dec_to_bin(*operating_1.br_code, number_bin, number_of_rows);
    
    for(uint32_t i = 0; i < number_of_rows; i++) {

        if(number_bin[i] == '0')
            number_bin[i] = '1';
        else if(number_bin[i] == '1')
            number_bin[i] = '0';
    }

    *result->br_code = convert_bin_to_dec(number_bin, number_of_rows);

    return result;
}

/************************************************************************
*                         Protecteds methods                            *
************************************************************************/

void BRC_Operator_Short::convert_dec_to_bin(uint64_t number_dec, char* number_bin, uint8_t size) {

    uint64_t current_value = 0;

    for(uint8_t i = (size-1) ; i >= 0; i--) {

        if(current_value < number_dec) {

            uint64_t pot = 1 << i;

            if((current_value + pot) <= number_dec) {

                current_value += pot;
                number_bin[i] = '1';
            }
            else
                number_bin[i] = '0';
        }
        else
            number_bin[i] = '0';

        if(i == 0)
            break;
    }
}

/***********************************************************************/

uint64_t BRC_Operator_Short::convert_bin_to_dec(char* number_bin, uint8_t size) {

    uint64_t current_value = 0;

    for(uint8_t i = 0; i < size; i++) {

        if(number_bin[i] == '1') {

            uint64_t value = 1 << i;
            current_value += value;
        }
    }

    return current_value;
}

/************************************************************************
*                          Privates methods                             *
************************************************************************/

/************************************************************************
*                           Statics methods                             *
************************************************************************/