//滑动窗口
#include<stdio.h>
#include<stdlib.h>
int lengthOfLongestSubstring(char* s)
{ //类似于hash的思想
	//滑动窗口维护
	int left = 0, right = 0;
	int max = 0;
	int i, j;
	int len = strlen(s);
	int havesamechar = 0;
	for (i = 0; i < len; i++)
	{
		if (left <= right)
		{ //检测是否出现重复
			 //循环遍历整个数组 left -> right
			havesamechar = 0;
			for (j = left; j < right; j++)
			{
				if (s[j] == s[right])
				{
					havesamechar = 1;
					break;
				}
			}
			if (havesamechar)
			{
				left = j + 1;//指向下一个
			}
		}
		//统计最大的间距
		max = max < (right - left + 1) ? (right - left + 1) : max;
		right++;
	}
	return max;
}