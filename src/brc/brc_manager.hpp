#ifndef BRC_MANAGER_HPP
#define BRC_MANAGER_HPP


#include <cstdint>
#include <map>
using std::map;
#include <string>
using std::string;
#include <set>
using std::set;

#include "brc/brc_operations.hpp"
#include "brc/br_code/br_code.hpp"
#include "brc/brc_operator/brc_operator.hpp"


/**
 * This class manage the operations with BR_Code.
 * @author Micael Popping.
*/
class BRC_Manager : BRC_Operations {

private:
    uint8_t inputs_number;
    map<string, BR_Code*> table;
    BR_Code *const_true;
    BR_Code *const_false;
    BRC_Operator* brc_operator;

public:
    BRC_Manager();
    BRC_Manager(set<string>& inputs);
    ~BRC_Manager();

    /**
     * @param input
    */
    void insert(string input);

    /**
     * These methods assign values to the inputs.
    */
    void generate_values();

    /**
     * @param set containing the inputs.
    */
    void generate_values(set<string>& inputs);

    /**
     * 
    */
    BR_Code* brc_input_of(string input);

    /**
     * BRC_Operations methods
    */
    BR_Code* execute_and(BR_Code& operating_1, BR_Code& operating_2);
    BR_Code* execute_or(BR_Code& operating_1, BR_Code& operating_2);
    BR_Code* execute_not(BR_Code& operating_1);
    BR_Code* execute_maj3(BR_Code& operating_1, BR_Code& operating_2, BR_Code& operating_3);

private:
    /**
     * This method defines the operator to use.
    */
    void initialize_operator();

    /**
     * This method asks the operator of the inputs values.
    */
    void start_values();
};

#endif //BRC_MANAGER_HPP