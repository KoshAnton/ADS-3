// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxVal = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } 
    else {
      num = 3 * num + 1;
    }
    if (num > maxVal) {
      maxVal = num;
    }
  }
  return maxVal;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } 
    else {
      num = 3 * num + 1;
    }
    length++;
  }
  return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int max_length = 0;
  unsigned int result_num = lbound;
  for (uint64_t num = lbound; num <= rbound; num++) {
    unsigned int currentlen = collatzLen(num);
    if (currentlen > max_length) {
      max_length = currentlen;
      result_num = num;
    }
  }
  return result_num;
}
