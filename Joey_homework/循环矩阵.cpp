#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int x = 0, y = 0, i = 1;

    for (int m = 1; m <= (n + 1) / 2; m++) {
        int temp = n + 1 - 2 * m;
        if (temp != 0) {
            for (int a = 1; a <= 4; a++) {
                for (int j = 0; j < temp; j++) {
                    matrix[x][y] = i;
                    if (a == 1) y++;
                    else if (a == 2) x++;
                    else if (a == 3) y--;
                    else if (a == 4) x--;
                    i++;
                }
                if (a == 4) {
                    x++;
                    y++;
                }
            }
        }
        else {
            matrix[x][y] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
