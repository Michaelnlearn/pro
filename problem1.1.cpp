#include <iostream>
#include <regex>
#include <string>
using namespace std;

int tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
//将十六进制的字符串转换成整数
long str_num16(char s[])
{
	int i;
	long n = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	else
		i = 0;
	for (; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'); ++i)
	{
		if (tolower(s[i]) > '9')
			n = 16 * n + (10 + tolower(s[i]) - 'a');
		else
			n = 16 * n + (tolower(s[i]) - '0');
	}
	return n;
}
//将十进制的字符串转换成整数
long str_num10(char *str)
{
	char *p;
	long x = 0;
	int i = 0;

	for (p = str; *p != '\0'; p++)https://fanyi.baidu.com/?aldtype=16047#auto/zh
	{
		if (*p >= '0' && *p <= '9')
			i = *p - '0';
		x = x * 10 + i;
	}
	return x;
}

int main(int argc, char **argv)
{
	long s = 0;
	long s1 = 0;
	long sum = 0;
	/*检查是否两个输入*/
	if (argc - 1 != 2)
	{
		cout << "ERROR" << endl;
		return 1;
	}
	/*检查输入长度是否不超过10*/
	const string arg1 = argv[1];
	const string arg2 = argv[2];
	if (arg1.length() > 10 || arg2.length() > 10)
	{
		cout << "ERROR" << endl;
		return 1;
	}
	string pattern = "0[xX][0-9a-fA-F]+";
	regex re(pattern);
	string pattern2 = "^[0-9]*$";
	regex reg(pattern2);
	/*判断第一个输入是否符合16进制或是10进制*/
	if (!regex_match(arg1, re) && !regex_match(arg1, reg))
	{
		cout << "ERROR" << endl;
		return 1;
	}
	/*判断第二个输入是否符合16进制或是10进制*/
	if (!regex_match(arg2, reg) && !regex_match(arg2, re))
	{
		cout << "ERROR" << endl;
		return 1;
	}
	// 未考虑两个输入都是16进制或是10进制 //
	if (regex_match(arg1, re))
	{
		s = str_num16(argv[1]);
		s1 = str_num10(argv[2]);
	}
	else
	{
		s = str_num16(argv[2]);
		s1 = str_num10(argv[1]);
	}
	sum = s + s1;

	/*10进制数转换为16进制 */
	char buf[10] = { 0 };
	sprintf_s(buf, "0x%X", sum);

	cout << buf << "  " << sum << endl;
	return 0;
}

