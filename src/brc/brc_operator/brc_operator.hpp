#ifndef BRC_OPERATOR_HPP
#define BRC_OPERATOR_HPP


include "brc/br_code/br_code.hpp"
#include "brc/brc_operations.hpp"


class BRC_Operator : public BRC_Operations {

protected:
    const unsigned int NUMBER_OF_INPUTS;
    const unsigned int VECTOR_SIZE;

    
public:
    BRC_Operator(unsigned int number_of_inputs, unsigned int vector_size);
    virtual ~BRC_Operator();

    BR_Code* execute_and(BR_Code& operating_1, BR_Code& operating_2);
    BR_Code* execute_or(BR_Code& operating_1, BR_Code& operating_2);
    virtual BR_Code* execute_not(BR_Code& operating_1) = 0;
    BR_Code* execute_maj3(BR_Code& operating_1, BR_Code& operating_2, BR_Code& operating_3);

    virtual BR_Code* primary_value_at(int level) = 0;

    unsigned int get_vector_size();
};

#endif //BRC_OPERATOR_HPP