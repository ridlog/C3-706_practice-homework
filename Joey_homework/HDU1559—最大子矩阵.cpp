#include<iostream>
#include<fstream>
#include<algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
int dp[1100][1100];
int MAX;
int main()
{
    ifstream infile("in.txt");
    
    int i, j, n, m, x, y;
  
    infile >> n;
    infile >> m;
    infile >> x;
    infile >> y;
        MAX = 0;
   for(int i=1;i<=n;i++)
       for (int j = 1; j <= m;j++)
       {
           infile >> dp[i][j];
       }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
       
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                if (i >= x && j >= y)
                {
                    MAX = max(MAX, dp[i][j] - dp[i][j - y] - dp[i - x][j] + dp[i - x][j - y]);
                }
            }
        printf("%d\n", MAX);
    
    return 0;
}
