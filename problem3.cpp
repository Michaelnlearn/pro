#include <iostream>
#include <string>
#include <map>

using namespace std;

string substr(const string &src, int start, int end)
{
	string result = "";
	int len = src.length();
	if (len < end)
		return result;
	while (start != end)
		result += src[start++];
	return result;
}

void get_sub_string(const string &src, int len, map<string, int> &pool, int win_size)
{
	string tmp_value;
	for (int index = len - win_size; index >= 0; index--)
	{
		tmp_value = substr(src, index, index + win_size);
		pool[tmp_value] += 1;
	}
}

void printMap(map<string, int> &pool)
{
	map<string, int>::iterator start = pool.begin();
	map<string, int>::iterator end = pool.end();
	while (start != end)
	{
		cout << start->first << "  " << start->second << endl;
		start++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "ERROR" << endl;
		return 1;
	}
	map<string, int> pool;
	string parm = argv[1];
	int length = parm.length();

	get_sub_string(parm, length, pool, 2);
	get_sub_string(parm, length, pool, 3);
	printMap(pool);
	return 0;
}
