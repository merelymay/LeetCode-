#include "pub_head.h"
using namespace std;
int res = INT_MAX;

void dfs(vector<vector<int>>& matrix, int x, int y, int time) {
    if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || matrix[x][y] <= time) {
        return;
    }
    if (x == matrix.size()-1 && y == matrix[0].size()-1) {
        res = min(res, time);
        return;
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    for (int i = 0; i < 4; ++i) {
        dfs(matrix, x+dx[i], y+dy[i], time+1);
    }
}

int minTime(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    dfs(matrix, 0, 0, 0);
    return res;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> vec[i][j];
            }
        }
        int res = minTime(vec);
        cout << (res == INT_MAX ? -1 : res) << endl;
    }
    return 0;
}