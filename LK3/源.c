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
//    //������
//    int s_len = strlen(s);
//    if (!s_len) return "";
//    int i = 0;
//    int start, len = 0; // ��¼�Ӵ��Ŀ�ʼλ�ã��Լ�����
//    int left, right;// ������Ԫ����������ɢ������±�
//    // ����
//    for (; i < s_len; i++) {
//        left = i - 1, right = i + 1;
//        help(s, left, right, s_len, &start, &len); // ��ȡ�������벿��          
//    }
//    // ż��
//    for (i = 0; i < s_len; i++) {
//        left = i, right = i + 1;
//        help(s, left, right, s_len, &start, &len); // ���������±꣬���ص�ǰi�µ��������Ӵ���Ȼ�����ѭ��i
//    }
//    s[start + len - 1] = '\0'; // �����Ӵ�������λ��
//    return s + start; //�����Ӵ���ʼ��λ��
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
		int len1 = expandAroundCenter(s, i, i);//һ��Ԫ��Ϊ����
		int len2 = expandAroundCenter(s, i, i + 1);//����Ԫ��Ϊ����
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
	{// ������left��rightΪ���ĵĻ��Ĵ�����
		L--;
		R++;
	}
	return R - L - 1;
}
