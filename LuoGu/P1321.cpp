#include <bits/stdc++.h>//c++����ͷ�ļ� 
using namespace std;//�����ռ�~

int main() {//������
	int boy = 0, girl = 0; //boy��girl�������¸��Եĸ���
	string st;//������Ŀ�������ַ���
	cin >> st; //�������У�����ܿ��ö�������~
	for (int i = 0; i <= st.length(); i++) { //��ʼ���Ӽ������ǿ���ܣ�
//st.length()Ϊ��ȡ�ַ������ȵĺ�����c++�������stringͷ�ļ��������Ҿ�ֱ��������ͷ�ļ���~
		if (st[i] == 'b' || st[i + 1] == 'o' || st[i + 2] == 'y') //�ж����ŵ�������ĸ�Ƿ�Ϊb��o��y
			boy++;//boy��������һ
		if (st[i] == 'g' || st[i + 1] == 'i' || st[i + 2] == 'r' || st[i + 3] == 'l') //�ж����ŵ�������ĸ�Ƿ�Ϊg��i��r��l
			girl++;//girl��������һ
	}
	cout << boy << endl; //���boy�ĸ���  ����~
	cout << girl << endl; //���girl�ĸ���
	return 0;//���ؽ�������~~~~
}