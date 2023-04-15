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
	//�ָ�
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
		//С��0.0
		cout << reverse( split1.length(), split1) << "." << reverse(removeZero(split2).length(), removeZero(split2));
	} else if (delimiter == '/') {
		//����
		cout << reverse( split1.length(), split1) << "/" << reverse(split2.length(), split2);
	} else if (delimiter == '%') {
		//�ٷ���
		cout << reverse(len - 1, str) << "%";
	} else {
		//����0
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

//��ת��ȥ������
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

//С������ת��ȥ��ǰ����
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
