/**
 * 题目46. 全排列
 * 描述：给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 */

#include "pub_head.h"

using namespace std;

class Solution {
private:
        vector<vector<int>> res;
        vector<int> tmp;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        backtrack(nums, visited);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& visited) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            tmp.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, visited);
            tmp.pop_back();
            visited[i] = false;
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> res;
    res = s.permute(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout<< res[i][j] << ',';
        }
        cout<<endl;
    }
}