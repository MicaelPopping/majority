#ifndef BRC_OPERATOR_S5_HPP
#define BRC_OPERATOR_S5_HPP


#include <cstdint>

#include "brc/brc_operator/brc_operator_short.hpp"


class BRC_Operator_S5 : public BRC_Operator_Short {

public:
    BRC_Operator_S5();

    BR_Code* primary_value_at(uint8_t level);
};

#endif //BRC_OPERATOR_S5_HPP