//��������
#include<stdio.h>
#include<stdlib.h>
int lengthOfLongestSubstring(char* s)
{ //������hash��˼��
	//��������ά��
	int left = 0, right = 0;
	int max = 0;
	int i, j;
	int len = strlen(s);
	int havesamechar = 0;
	for (i = 0; i < len; i++)
	{
		if (left <= right)
		{ //����Ƿ�����ظ�
			 //ѭ�������������� left -> right
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
				left = j + 1;//ָ����һ��
			}
		}
		//ͳ�����ļ��
		max = max < (right - left + 1) ? (right - left + 1) : max;
		right++;
	}
	return max;
}