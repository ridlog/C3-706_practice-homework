#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int a[N], n;

void shellSort(int *a, int len)
{
    int i, j, k, tmp, gap;                         // gap 为步长
    for (gap = len / 2; gap > 0; gap /= 2) {       // 步长初始化为数组长度的一半，每次遍
        for (i = 0; i < gap; ++i) {                // 变量 i 为每次分组的第一个元素下标
            for (j = i + gap; j < len; j += gap) { // 对步长为gap的元素进行直插排
                tmp = a[j];                        // 备份a[i]的值
                k = j - gap;                       // j初始化为i的前一个元素（与i相差gap长度）
                while (k >= 0 && a[k] > tmp) {
                    a[k + gap] = a[k]; // 将在a[i]前且比tmp的值大的元素向后移动一位
                    k -= gap;
                }
                a[k + gap] = tmp;
            }
        }
    }
}
signed main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int i = 0;
    int x;
    while (scanf("%d", &x)) {
        a[i++] = x;
        char c = cin.get();
        if (c != ' ') {
            break;
        }
    }
    n = i;
    shellSort(a, n);
    for (int j = 0; j < n; ++j)
        cout << a[j] << ' ';
    return 0;
}