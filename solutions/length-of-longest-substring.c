#include <string.h>
#include "solution.h"

int lengthOfLongestSubstring(char* s) {
	int currentMax = 0;
	int i = 0;
	int j = 0;
	char *res = malloc(strlen(s));
	res[0] = '\0';
	int res_len = 0;
	// // 主循环
	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != '\0')
		{
			if (!(strchr(res, s[j]) == NULL))
			{
				res[0] = '\0';
				break;
			}
			else
			{
				res_len = strlen(res);
				res[res_len] = s[j];
				res[res_len + 1] = '\0';
				if (res_len + 1 > currentMax)
				{
					currentMax = res_len + 1;
				}
				j++;
			}
		}
		i++;
	}
	return currentMax;
}