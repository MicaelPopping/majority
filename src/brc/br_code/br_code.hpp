#ifndef BRC_BR_CODE_HPP
#define BRC_BR_CODE_HPP


#include <cstdint>


class BR_Code {

public:
    const uint8_t INPUTS_NUMBER; // 0 - 10(255) inputs.
    uint64_t *br_code; // Vector of the brcs.

public:
    BR_Code(uint8_t inputs_number, uint8_t vector_size = 1); // vector_size 0 - 16(255) vectors.
    ~BR_Code();
};

#endif //BRC_BR_CODE_HPP