#include "brc/brc_operator/brc_operator.hpp"


/************************************************************************
*                           Publics methods                             *
************************************************************************/

BRC_Operator::BRC_Operator(uint8_t inupts_number, uint8_t vector_size) 
: INPUTS_NUMBER(inupts_number), VECTOR_SIZE(vector_size) {}

/************************************************************************/

BRC_Operator::~BRC_Operator() {}

/************************************************************************/

BR_Code* BRC_Operator::execute_and(BR_Code& operating_1, BR_Code& operating_2) {

    if(!((operating_1.INPUTS_NUMBER == operating_2.INPUTS_NUMBER) && (operating_1.INPUTS_NUMBER == INPUTS_NUMBER)))
        return nullptr;

    BR_Code* result = new BR_Code(INPUTS_NUMBER, VECTOR_SIZE);

    for(unsigned int i = 0; i < VECTOR_SIZE; i++)
        result->br_code[i] = operating_1.br_code[i] & operating_2.br_code[i];

    return result;
}

/************************************************************************/

BR_Code* BRC_Operator::execute_or(BR_Code& operating_1, BR_Code& operating_2) {

    if(!((operating_1.INPUTS_NUMBER == operating_2.INPUTS_NUMBER) && (operating_1.INPUTS_NUMBER == INPUTS_NUMBER)))
        return nullptr;

    BR_Code* result = new BR_Code(INPUTS_NUMBER, VECTOR_SIZE);

    for(unsigned int i = 0; i < VECTOR_SIZE; i++)
        result->br_code[i] = operating_1.br_code[i] | operating_2.br_code[i];

    return result;
}

/************************************************************************/

BR_Code* BRC_Operator::execute_maj3(BR_Code& operating_1, BR_Code& operating_2, BR_Code& operating_3) {

    if(!((operating_1.INPUTS_NUMBER == operating_2.INPUTS_NUMBER) && (operating_1.INPUTS_NUMBER == operating_3.INPUTS_NUMBER) && (operating_1.INPUTS_NUMBER == INPUTS_NUMBER)))
        return nullptr;

    BR_Code* in_11 = nullptr;
    BR_Code* in_12 = nullptr;
    BR_Code* in_13 = nullptr;
    BR_Code* in_21 = nullptr;
    BR_Code* result = nullptr;

    in_11 = execute_and(operating_1, operating_2);
    in_12 = execute_and(operating_1, operating_3);
    in_13 = execute_and(operating_2, operating_3);

    in_21 = execute_or(*in_11, *in_12);
    result = execute_or(*in_21, *in_13);

    delete in_11;
    delete in_12;
    delete in_13;
    delete in_21;

    return result;
}

/************************************************************************/

uint8_t BRC_Operator::get_vector_size() {

    return VECTOR_SIZE;
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