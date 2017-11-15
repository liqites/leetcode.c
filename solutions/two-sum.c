#include "solution.h"

int* twoSum(int* nums, int numsSize, int target) {
  static int r[2];
  int a, b = 0;
  for(int i = 0; i < numsSize; i++) {
    a = nums[i];
    for(int j = i + 1; j < numsSize; j++) {
      b = nums[j];

      if( a + b == target) {
        r[0] = i;
        r[1] = j;
        return r;
      }
    }
  }
  return r;
}
