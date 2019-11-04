#ifndef BRC_OPERATOR_SHORT_HPP
#define BRC_OPERATOR_SHORT_HPP


#include <cstdint>

#include "brc/brc_operator/brc_operator.hpp"


class BRC_Operator_Short : public BRC_Operator {

public:
    BRC_Operator_Short(uint8_t inputs_number);
    virtual ~BRC_Operator_Short();

    BR_Code* execute_not(BR_Code& operating_1);

    virtual BR_Code* primary_value_at(uint8_t level) = 0;

protected:
    void convert_dec_to_bin(uint64_t number_dec, char* number_bin, uint8_t size);
    uint64_t convert_bin_to_dec(char* number_bin, uint8_t size);
};

#endif //BRC_OPERATOR_SHORT_HPP