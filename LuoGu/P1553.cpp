#include <iostream>
#include <cstring>
using namespace std;
char  findDelimiter(string str);
string reverse(int len, string str);
string removeZero(string str);

int main() {
	string str;
	cin >> str;
	string split1, split2;
	char delimiter = findDelimiter(str);
	int len = str.length();
	//分割
	if (delimiter != ' ' && delimiter != '%') {
		int pos = 0;
		for (auto s : str) {
			if (s == delimiter)
				pos++;
			else	if (pos == 1 )
				split2 += s;
			else
				split1 += s;
		}
	}
	if (delimiter == '.') {
		//小数0.0
		cout << reverse( split1.length(), split1) << "." << reverse(removeZero(split2).length(), removeZero(split2));
	} else if (delimiter == '/') {
		//分数
		cout << reverse( split1.length(), split1) << "/" << reverse(split2.length(), split2);
	} else if (delimiter == '%') {
		//百分数
		cout << reverse(len - 1, str) << "%";
	} else {
		//整数0
		cout << reverse(len, str);
	}
	return 0;
}

char  findDelimiter(string str) {
	for (auto s : str ) {
		if (s == '.')
			return '.';
		if (s == '/')
			return '/';
		if (s == '%')
			return '%';
	}
	return  ' ';
}

//反转加去除后导零
string reverse(int len, string str) {
	string s  ;
	int zero = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] != '0')
			zero = 1;
		if (zero) {
			s += str[i];
		}
	}
	if (!zero)
		s = "0";
	return s;
}

//小数：反转加去除前导零
string removeZero(string str) {
	string s ;
	int zero = 0;
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '0')
			zero = 1;
		if (zero)
			s += str[i];
	}
	return s;
}
