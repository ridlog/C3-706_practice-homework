#include<iostream>
#include<algorithm>
using namespace std;
class Number
{
public:
int a;
int factor[10];
int j = 0;
int max_number;
int FindFactor()
{
	for (int i = 2; i < a; i++)
	{
		bool flag = true;
		if (a % i == 0)
		{
			for (int m = 2; m < i; m++)
			{
				if (i% m == 0)
					flag = false;
			}
			if (flag ==true)
			{
				factor[j] = i;
				j++;
			}
		}
			
	}
	return 0;
}
int sort_Factor()
{
	sort(factor, factor + 9, greater<int>());
	max_number = factor[0];
	
		return 0;
}
};

int main()
{
	Number Num[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> Num[i].a;
		Num[i].FindFactor();
		Num[i].sort_Factor();
	}
	int temp=0;
	int max=Num[temp].max_number;
	for (int i = 0; i < 5; i++)
	{
		if (Num[i].max_number > max)
		{
			max = Num[i].max_number;
			temp = i;
		}
	}
	cout << "the number that owns the largest prime factor is:" << Num[temp].a;
}
