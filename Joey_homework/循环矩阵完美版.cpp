#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int matrix[100][100] = { 0, };
	int x = 0, y = 0, i = 1;
	int temp = 0;//每次循环边的数字个数。
	for (int m = 1; m <= (n + 1) / 2; m++)//循环次数
	{
		temp = n + 1 - 2 * m;
		if (!temp == 0)
		{
			for (int a = 1; a <= 4; a++)//每次循环内部进行四次循环
			{
				if (a == 1)
				{
					for (int j = 0; j < temp; y++, i++, j++)
					{
						matrix[x][y] = i;
					}

				}
				else if (a == 2)
				{
					for (int j = 0; j < temp; x++, i++, j++)
					{
						matrix[x][y] = i;

					}

				}
				else if (a == 3)
				{
					for (int j = 0; j < temp; y--, i++, j++)
					{
						matrix[x][y] = i;
					}

				}
				else if (a == 4)
				{
					for (int j = 0; j < temp; x--, i++, j++)
					{
						matrix[x][y] = i;
					}
					x++;
					y++;

				}


			}
		}
		else if (temp == 0)
		{
			matrix[x][y] = i;
		}
	}
		 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
