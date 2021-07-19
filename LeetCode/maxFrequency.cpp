// 1838. 最高频元素的频数
// 元素的 频数 是该元素在一个数组中出现的次数。
// 给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。
// 执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。
// 示例 1：
// 输入：nums = [1,2,4], k = 5
// 输出：3
// 解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
// 4 是数组中最高频元素，频数是 3 。

#include "pub_head.h"
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0, res = 0;
        int n = nums.size();
        for (int i = 0, j = 0; j < n; ++j) {
            while (nums[j]*(j-i+1) - sum> k) {
                sum -= nums[i++];
            }
            sum += nums[j];
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 4};
    int k = 5;
    Solution s;
    int res = s.maxFrequency(nums, k);
    cout << res;
    return 0;
}
