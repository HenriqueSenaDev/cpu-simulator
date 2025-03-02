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