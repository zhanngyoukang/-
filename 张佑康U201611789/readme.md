# ʹ��c++�����������
>������Դ��18������ʿ��һ����ѧ��Ϸ����һ������ֽ���ʽ���������߼���Ϸ�������Ҫ����9��9�����ϵ���֪���֣����������ʣ��ո�����֣�������ÿһ�С�ÿһ�С�ÿһ�����߹���3*3���ڵ����־���1-9�����ظ���

��Ϊ�����������ʹ����ٷ�������Ѷ��ʺϣ�������ѡ�����c++���������������Ϊ�ҵ�������ҵ��

## ���˼·Ϊ��
�ڿո�����n���ж��Ƿ���С�Ź���ͺ��������Ŷ��Ϸ����򷵻���ȷ��֮��ʹ��ö�ٷ��ظ��˹��̡��õ�����������
## �������£�
```c++
#include <iostream>

using namespace std;

bool sign = false;

int num[9][9];

void Input();
void Output();
bool Check(int n, int key);
int DFS(int n);

int main()
{
	cout << "����һ��9*9����������:" << endl;
	Input();
	DFS(0);
	Output();
	system("pause");
}

void Input()
{
	char temp[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> temp[i][j];
			num[i][j] = temp[i][j] - '0';
		}
	}
}

void Output()
{
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << num[i][j] << " ";
			if (j % 3 == 2)
			{
				cout << "   ";
			}
		}
		cout << endl;
		if (i % 3 == 2)
		{
			cout << endl;
		}
	}
}

bool Check(int n, int key)
{
	for (int i = 0; i < 9; i++)
	{
		int j = n / 9;
		if (num[j][i] == key) return false;
	}
	for (int i = 0; i < 9; i++)
	{
		int j = n % 9;
		if (num[i][j] == key) return false;
	}
	int x = n / 9 / 3 * 3;
	int y = n % 9 / 3 * 3;
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (num[i][j] == key) return false;
		}
	}
	return true;
}

int DFS(int n)
{
	if (n > 80)
	{
		sign = true;
		return 0;
	}
	if (num[n / 9][n % 9] != 0)
	{
		DFS(n + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (Check(n, i) == true)
			{
				num[n / 9][n % 9] = i;
				DFS(n + 1);
				if (sign == true) return 0;
				num[n / 9][n % 9] = 0;
			}
		}
	}
}
```
![��������](����ͼƬ/����.png "����������������н��")