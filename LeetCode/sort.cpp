#include "pub_head.h"
using namespace std;



class MySort {
public:
    /* 快速排序
    * 基本思想： 通过一趟排序将待排记录分隔成独立的两部分，使其中一部分记录的关键字均比另外一部分的关键字小；
    * 算法分析： 时间复杂度 最好情况O(nlogn) 最坏情况(n^2) 平均情况(nlogn)
    *           空间复杂度 最好情况O(logn)  最坏情况O(n)
    * 快排是不稳定算法   每次选到的基准值为最值时为最坏情况
    */
    void quickSort(vector<int>& nums, int low, int high) {
        static int cnt = 0;
        if (low < high) {
            // printNums(nums, cnt++);
            int idx = partition(nums, low, high);
            quickSort(nums, low, idx - 1);
            quickSort(nums, idx + 1, high);
        }
    };

private:
    void printNums(vector<int>& nums, int idx) {
        cout << "第" << idx << "次排序结果：" <<endl;
        // for (int i : nums) {
        //     cout << i << " ";
        // }
        cout << endl << endl;
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= pivot) {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
};

int main() {
    // vector<int> nums = {2, 4, 13, 8, 23, 0, 3, 65, 43, 4, 45, 99};
    vector<int> randNum;
    srand(time(nullptr));
    for (int i = 0; i < 1000000; ++i) {
        randNum.emplace_back(rand());
    }

    MySort ms;
    auto startTime = chrono::steady_clock::now();
    // 千万数据  3.05s
    // sort(randNum.begin(), randNum.end());
    // 千万数据 4.65s
    ms.quickSort(randNum, 0, randNum.size() - 1);
    auto currentTime = chrono::steady_clock::now();
    chrono::duration<double, milli> elapsed = currentTime - startTime;
    cout << "time: " << elapsed.count() / 1000 << "s";
    return 0;
}