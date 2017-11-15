#include "solution.h"

/*
 * 
 */
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
  int mid_idx = 0;
  int sum = nums1Size + nums2Size;
  int is_even = 0;

  if (sum % 2 == 0)
  {
    mid_idx = sum / 2;
    is_even = 1;
  }
  else
  {
    mid_idx = sum / 2 + 1;
  }

  int *p_num1 = nums1;
  int *p_num2 = nums2;

  if (nums1Size == 0)
  {
    p_num1 = NULL;
  }

  if (nums2Size == 0)
  {
    p_num2 = NULL;
  }

  int nums1Size_left = nums1Size;
  int nums2Size_left = nums2Size;

  int left = mid_idx;
  int divider = 0;

  int mid_1 = 0, mid_2 = 0;
  while (left > 1)
  {
    divider = left / 2;
    // 如果数组1 已经结束了
    if (p_num1 == NULL)
    {
      p_num2 = &p_num2[left - 1];
      left = 1;
      break;
    }

    // 如果数组2 结束了
    if (p_num2 == NULL)
    {
      p_num1 = &p_num1[left - 1];
      left = 1;
      break;
    }

    // printf("divider = %d, left = %d\n", divider, left);

    // 如果都没有结束
    if (divider >= nums1Size_left)
    {
      mid_1 = p_num1[nums1Size_left - 1];
    }
    else
    {
      mid_1 = p_num1[divider - 1];
    }

    if (divider >= nums2Size_left)
    {
      mid_2 = p_num2[nums2Size_left - 1];
    }
    else
    {
      mid_2 = p_num2[divider - 1];
    }

    // printf("mid_1 = %d, mid_2 = %d \n p_num1[0] = %d, p_num2[0] = %d\n", mid_1, mid_2, p_num1[0], p_num2[0]);

    // 比较
    if (mid_1 > mid_2)
    {
      if (divider >= nums2Size_left)
      {
        p_num2 = NULL;
        left = left - nums2Size_left;
        nums2Size_left = 0;
        continue;
      }
      else
      {
        // 删除数组2 的前 divider 个数字
        p_num2 = &p_num2[divider];
        nums2Size_left = nums2Size_left - divider;
      }
    }
    else
    {
      if (divider >= nums1Size_left)
      {
        p_num1 = NULL;
        left = left - nums1Size_left;
        nums1Size_left = 0;
        continue;
      }
      else
      {
        // 删除数组1 的前 divider 个数字
        p_num1 = &p_num1[divider];
        nums1Size_left = nums1Size_left - divider;
      }
    }
    left = left - divider;
  }

  if (!is_even)
  {
    if (p_num1 == NULL)
    {
      return p_num2[0];
    }
    if (p_num2 == NULL)
    {
      return p_num1[0];
    }
    if (p_num1[0] <= p_num2[0])
    {
      return p_num1[0];
    }
    else
    {
      return p_num2[0];
    }
  }
  else
  {
    if (p_num1 == NULL)
    {
      return (p_num2[0] + p_num2[1]) / 2.0;
    }
    if (p_num2 == NULL)
    {
      return (p_num1[0] + p_num1[1]) / 2.0;
    }
    // 这时候，两个指针指向的不一定是最小。
    if (nums1Size_left > 1 && p_num1[1] < p_num2[0])
    {
      return (p_num1[0] + p_num1[1]) / 2.0;
    }

    if (nums2Size_left > 1 && p_num2[1] < p_num1[0])
    {
      return (p_num2[0] + p_num2[1]) / 2.0;
    }

    return (p_num1[0] + p_num2[0]) / 2.0;
  }
}