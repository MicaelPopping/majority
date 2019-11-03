#ifndef BRC_OPERATIONS_HPP
#define BRC_OPERATIONS_HPP


#include "brc/br_code/br_code.hpp"


class BRC_Operations {

public:
    virtual BR_Code* execute_and(BR_Code& operating_1, BR_Code& operating_2) = 0;
    virtual BR_Code* execute_or(BR_Code& operating_1, BR_Code& operating_2) = 0;
    virtual BR_Code* execute_not(BR_Code& operating_1) = 0;
    virtual BR_Code* execute_maj3(BR_Code& operating_1, BR_Code& operating_2, BR_Code& operating_3) = 0;
};

#endif //BRC_OPERATIONS_HPP