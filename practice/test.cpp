#include "pub_head.h"
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix) {
    int res = INT_MIN;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
        vector<int> sums(n, 0);
        for (int j = i; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                sums[k] += matrix[j][k];
            }
            // 这里求sums的最大子序和
            int s = sums[0];
            vector<int> dp(n);
            dp[0] = sums[0];
            for (int i = 1; i < sums.size(); ++i) {
                dp[i] = max(sums[i], dp[i-1]+sums[i]);
                s = max(s, dp[i]);
            }
            res = max(res, s);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> a = {{-3,5,-1,5}, {2,4, -2, 4}, {-1, 3, -1, 3}};
    int res = maxSumSubmatrix(a);
    cout<<res;
    return 0;
}