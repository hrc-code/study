#include <iostream>
using namespace std;
int count[30];

char alphabet[30] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main() {
	string line;
	int N = 4;
	//读取元素
	while (N--) {
		getline(cin, line);
		for (int i = 0; i < line.length(); i++) {
			for (int j = 0; j < 26; j++) {
				if (line[i] == alphabet[j])
					count[j]++;
			}
		}
	}
	//获取最终行数
	int  row = 0;
	for (int i = 0; i < 26; i++) {
		if (count[i]) {
			if (count[i] > row)
				row = count[i];
		}
	}
	//填充数组
	char table[row][26];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < 26; j++)
			table[i][j] = '*';
	for (int i = 0; i < 26; i++) {
		if (count[i]) {
			for (int j = 0; j < row - count[i]; j++) {
				table[j][i] = ' ';
			}
		} else {
			for (int j = 0; j < row; j++)
				table[j][i] = ' ';
		}
	}
	//按照题目格式输出
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 26; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";


	return 0;
}