#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char table1[30][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};
int table2[30] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 0, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};
int ans[10];
char ch[100];
int main() {
	//char [i][j]二维字符数组可以存放字符串 i表示字符串的个数  j表示字符串的容量
	//寻找子窜---cin 
	// 并且将子窜转换为对应的数字，(数字先平方再%100)--建表，再按照升序排列--sort，
	// 最后将全部数字输出---第一个数字去零，其余数字补零成两位数--printf("%.2d");

	int count = 0;
	for (int i = 0; i < 6; i++) {
		cin >> ch;
		for (int j = 0; j < 30; j++)
			if (!strcmp(ch, table1[j])) {
				ans[count++] = table2[j];
				break;
			}
	}
	int flag = 0;
	sort(ans, ans + count);
	for (int i = 0; i < count; i++) {
		if (flag) {
			printf("%.2d", ans[i]);
		} else {
			if (ans[i]) {
				flag = 1;
				cout << ans[i];
			}
		}
	}
	if (!flag)
		cout << "0";
	return 0;
}