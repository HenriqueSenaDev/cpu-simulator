#include <stdint.h>
#include <string.h>

uint16_t *binaryToDecimal(uint8_t *bits, int from, int to)
{
  uint16_t *decimal = (uint16_t *)calloc(1, sizeof(uint16_t));
  int digitsCount = 0;

  if (decimal == NULL)
  {
    perror("Error on alocate memory to parse binary to decimal.");
    exit(1);
  }

  for (int i = to; i >= from; i--)
  {
    if (bits[i])
      *decimal += pow(2, digitsCount);

    digitsCount++;
  }

  return decimal;
}

uint8_t *decimalToBinary(uint16_t decimal)
{
  uint8_t *binaryArr = (uint8_t *)calloc(16, sizeof(uint8_t));

  for (int i = 0; i < 16; i++)
  {
    uint8_t bit = decimal % 2; // 0 or 1
    binaryArr[i] = bit;

    decimal = decimal >> 1;
  }

  return binaryArr;
}