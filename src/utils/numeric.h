#include <stdint.h>
#ifndef NUMERIC_UTILS
#define NUMERIC_UTILS

uint16_t *binaryToDecimal(uint8_t *instructionBits, int from, int to);
uint8_t *decimalToBinary(uint16_t decimal);

#endif
