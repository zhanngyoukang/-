# 使用c++解决数独问题
>数独是源自18世纪瑞士的一种数学游戏。是一种运用纸、笔进行演算的逻辑游戏。玩家需要根据9×9盘面上的已知数字，推理出所有剩余空格的数字，并满足每一行、每一列、每一个粗线宫（3*3）内的数字均含1-9，不重复。

因为数独问题可以使用穷举法解决，难度适合，所以我选择设计c++程序解数独问题作为我的暑期作业。

## 设计思路为：
在空格处填入n，判断是否在小九宫格和横排与竖排都合法，则返回正确；之后使用枚举法重复此过程。得到结果后输出。
## 代码如下：
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
	cout << "输入一个9*9的数独矩阵:" << endl;
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
![数独举例](数独图片/数独.png "这是数独程序的运行结果")