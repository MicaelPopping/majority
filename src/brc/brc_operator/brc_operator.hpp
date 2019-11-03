#ifndef BRC_OPERATOR_HPP
#define BRC_OPERATOR_HPP


#include <cstdint>

#include "brc/brc_operations.hpp"
#include "brc/br_code/br_code.hpp"


class BRC_Operator : public BRC_Operations {

protected:
    const uint8_t INPUTS_NUMBER;
    const uint8_t VECTOR_SIZE;

    
public:
    BRC_Operator(uint8_t inputs_number,  uint8_t vector_size);
    virtual ~BRC_Operator();

    BR_Code* execute_and(BR_Code& operating_1, BR_Code& operating_2);
    BR_Code* execute_or(BR_Code& operating_1, BR_Code& operating_2);
    virtual BR_Code* execute_not(BR_Code& operating_1) = 0;
    BR_Code* execute_maj3(BR_Code& operating_1, BR_Code& operating_2, BR_Code& operating_3);

    virtual BR_Code* primary_value_at(uint8_t level) = 0;

    uint8_t get_vector_size();
};

#endif //BRC_OPERATOR_HPP