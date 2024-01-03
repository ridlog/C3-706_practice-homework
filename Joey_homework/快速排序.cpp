#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iterator>
using namespace std;
int QuickSort1(vector<int>& r, int s, int t)
{
	int i = s, j = t;
	int base = r[s];
	while (i < j)
	{
		while(i<j&&r[j]>base)
		{
			j--;
		}
		if (i < j)
		{
			r[i] = r[j];
			i++;
		}
		while(i<j&&r[i] <= base)
		{
			i++;
		}
		if (i < j)
		{
			r[j] = r[i];
			j--;
		}
	}
	r[i] = base;
	return i;
}
void quicksort(vector<int>&r,int s,int t)
{
	if (s < t)
	{
		int i = QuickSort1(r, s, t);
		quicksort(r, s, i - 1);
		quicksort(r, i + 1, t);
	}
}

void quicksort1(vector<int>& r, int n)
{
	quicksort(r, 0, n - 1);
}
int main()
{
	ifstream infile("in.txt");
	ofstream outfile("out.txt");
	if (!infile.is_open()&&!outfile.is_open())
	{
		std::cerr << "无法打开文件" << endl;
	}
	vector<int> r;
	string line;
	getline(infile, line);
	istringstream iss(line);//istringstream类用于执行C++风格的串流的输入操作。定义了一种输入方式：iss。在这种输入方式中，将会以空格为分界、逐个读取。
	int number=0;
	r.insert(r.end(), istream_iterator<int>(iss), istream_iterator<int>());
	int n = r.size();
	quicksort1(r, n);
	for (int num : r)
	{
		outfile << num << " ";
	}
}