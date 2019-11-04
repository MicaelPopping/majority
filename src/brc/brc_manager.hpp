#ifndef BRC_MANAGER_HPP
#define BRC_MANAGER_HPP


#include <cstdint>
#include <map>
using std::map;
#include <string>
using std::string;

#include "brc/br_code/br_code.hpp"
#include "brc/brc_operator/brc_operator.hpp"


/**
 * This class manage the operations with BR_Code.
 * @author Micael Popping.
*/
class BRC_Manager {

private:
    uint8_t inputs_number;
    map<string, BR_Code*> table;
    BR_Code *const_true;
    BR_Code *const_false;
    BRC_Operator* brc_operator;

public:

};

#endif //BRC_MANAGER_HPP