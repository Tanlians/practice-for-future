//void help(char* s, int left, int right, int s_len, int* start, int* len) {
//    while (left >= 0 && right < s_len && s[left] == s[right]) {
//        left--, right++;
//    }
//    if (right - left > *len) {
//        *start = left + 1;
//        *len = right - *start + 1;
//    }
//}
//char* longestPalindrome(char* s) {
//    //暴力法
//    int s_len = strlen(s);
//    if (!s_len) return "";
//    int i = 0;
//    int start, len = 0; // 记录子串的开始位置，以及长度
//    int left, right;// 从中心元素向两边扩散，标记下标
//    // 奇数
//    for (; i < s_len; i++) {
//        left = i - 1, right = i + 1;
//        help(s, left, right, s_len, &start, &len); // 提取公共代码部分          
//    }
//    // 偶数
//    for (i = 0; i < s_len; i++) {
//        left = i, right = i + 1;
//        help(s, left, right, s_len, &start, &len); // 输入左右下标，返回当前i下的最大回文子串，然后外层循环i
//    }
//    s[start + len - 1] = '\0'; // 设置子串结束的位置
//    return s + start; //返回子串开始的位置
//
//}

string longestPalindrome(string s)
{
	if (s.length() < 1)
	{
		return "";
	}
	int start = 0, end = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int len1 = expandAroundCenter(s, i, i);//一个元素为中心
		int len2 = expandAroundCenter(s, i, i + 1);//两个元素为中心
		int len = max(len1, len2);
		if (len > end - start)
		{
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	return s.substr(start, end - start + 1);
}

int expandAroundCenter(string s, int left, int right)
{
	int L = left, R = right;
	while (L >= 0 && R < s.length() && s[L] == s[R])
	{// 计算以left和right为中心的回文串长度
		L--;
		R++;
	}
	return R - L - 1;
}
