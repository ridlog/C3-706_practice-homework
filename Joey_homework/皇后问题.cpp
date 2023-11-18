#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Solution {
public:
    int col_mask, diag_mask, anti_diag_mask;
    int find_sol(int i, int n) {
        int num=0;
        if (i == n) 
            return 1;
        for (int j = 0; j < n; j++) {
            if ((col_mask & (1 << j)) == 0 && 
                (diag_mask & (1 << (i - j + n - 1))) == 0 && 
                (anti_diag_mask & (1 << (i + j))) == 0) 
            {
                col_mask |= (1 << j);
                diag_mask |= (1 << (i - j + n - 1));
                anti_diag_mask |= (1 << (i + j));

                num+=find_sol(i+1, n);

                col_mask &= ~(1 << j);
                diag_mask &= ~(1 << (i - j + n - 1));
                anti_diag_mask &= ~(1 << (i + j));
            }
        }
        return num;
    }
    int totalNQueens(int n) {
        col_mask = diag_mask = anti_diag_mask = 0;
        return find_sol(0, n);
    }
};
	
int main()
{
	int n;
	ifstream infile("in.txt");
	if (!infile.is_open())
	{
		cerr << "fail to open the file in.txt";
	}
	infile >> n;
	Solution s;
	cout << s.totalNQueens(n);
}
