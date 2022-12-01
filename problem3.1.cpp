#include <iostream>
#include <string>
using namespace std;

struct Line {
	double x1;
	double y1;
	double x2;
	double y2;
};

bool intersection(const Line& l1, const Line& l2)
{
	//快速排斥实验
	if ((l1.x1 > l1.x2 ? l1.x1 : l1.x2) < (l2.x1 < l2.x2 ? l2.x1 : l2.x2) ||
		(l1.y1 > l1.y2 ? l1.y1 : l1.y2) < (l2.y1 < l2.y2 ? l2.y1 : l2.y2) ||
		(l2.x1 > l2.x2 ? l2.x1 : l2.x2) < (l1.x1 < l1.x2 ? l1.x1 : l1.x2) ||
		(l2.y1 > l2.y2 ? l2.y1 : l2.y2) < (l1.y1 < l1.y2 ? l1.y1 : l1.y2))
	{
		return false;
	}
	//跨立实验
	if ((((l1.x1 - l2.x1) * (l2.y2 - l2.y1) - (l1.y1 - l2.y1) * (l2.x2 - l2.x1)) *
		((l1.x2 - l2.x1) * (l2.y2 - l2.y1) - (l1.y2 - l2.y1) * (l2.x2 - l2.x1))) > 0 ||
		(((l2.x1 - l1.x1) * (l1.y2 - l1.y1) - (l2.y1 - l1.y1) * (l1.x2 - l1.x1)) *
			((l2.x2 - l1.x1) * (l1.y2 - l1.y1) - (l2.y2 - l1.y1) * (l1.x2 - l1.x1))) > 0)
	{
		return false;
	}
	return true;
}

double char2dou(string s) {
	double ans = 0, sc = 1;
	bool flag = true;
	for (auto& c : s) {
		if (c == '.') {
			flag = false;
		}
		else if (flag) {
			ans *= 10;
			ans += c - '0';
		}
		else {
			sc /= 10;
			ans += (c - '0') * sc;
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	Line l1, l2;
	l1.x1 = char2dou(argv[1]);
	l1.x2 = char2dou(argv[2]);
	l1.y1 = char2dou(argv[3]);
	l1.y2 = char2dou(argv[4]);
	l2.x1 = char2dou(argv[5]);
	l2.x2 = char2dou(argv[6]);
	l2.y1 = char2dou(argv[7]);
	l2.y2 = char2dou(argv[8]);
	/*string arg[9];
	for (int i = 0; i < 9; i++) {
		cin >> arg[i];
	}
	l1.x1 = char2dou(arg[1]);
	l1.x2 = char2dou(arg[2]);
	l1.y1 = char2dou(arg[3]);
	l1.y2 = char2dou(arg[4]);
	l2.x1 = char2dou(arg[5]);
	l2.x2 = char2dou(arg[6]);
	l2.y1 = char2dou(arg[7]);
	l2.y2 = char2dou(arg[8]);*/
	if (intersection(l1, l2))
		cout << "TRUE";
	else
		cout << "FALSE";
	return 0;
}