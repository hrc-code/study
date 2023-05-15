#include <bits/stdc++.h>//c++万能头文件 
using namespace std;//命名空间~

int main() {//主函数
	int boy = 0, girl = 0; //boy和girl用来记下各自的个数
	string st;//定义题目给出的字符串
	cin >> st; //这个我们校长都能看得懂的输入~
	for (int i = 0; i <= st.length(); i++) { //开始发挥计算机的强大功能！
//st.length()为读取字符串长度的函数，c++中最好用string头文件，这里我就直接用万能头文件了~
		if (st[i] == 'b' || st[i + 1] == 'o' || st[i + 2] == 'y') //判断连着的三个字母是否为b、o、y
			boy++;//boy计数器加一
		if (st[i] == 'g' || st[i + 1] == 'i' || st[i + 2] == 'r' || st[i + 3] == 'l') //判断连着的三个字母是否为g、i、r、l
			girl++;//girl计数器加一
	}
	cout << boy << endl; //输出boy的个数  换行~
	cout << girl << endl; //输出girl的个数
	return 0;//愉快地结束程序~~~~
}