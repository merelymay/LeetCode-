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
            printNums(nums, cnt++);
            int idx = partition(nums, low, high);
            quickSort(nums, low, idx - 1);
            quickSort(nums, idx + 1, high);
        }
    };
    
    /* 归并排序
    * 归并排序 是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典
    * 型的应用。归并排序是一种稳定的排序方法。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，
    * 再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。
    *
    */
    void mergeSort(vector<int>& nums, int left, int right) {
        // static int cnt = 0;
        if (left < right) {
            // printNums(nums, cnt++);
            int mid = (left + right) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }
    
private:
    void printNums(vector<int>& nums, int idx) {
        cout << "第" << idx << "次排序结果：" <<endl;
        for (int i : nums) {
            cout << i << " ";
        }
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

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> vec(right-left+1);
        int p1 = left, p2 = mid+1, i = 0;
        while (p1 <= mid && p2 <= right) {
            vec[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
        }
        while (p1 <= mid) {
            vec[i++] = nums[p1++];
        }
        while (p2 <= right) {
            vec[i++] = nums[p2++];
        }
        for (int i = 0; i < vec.size(); ++i) {
            nums[left+i] = vec[i];
        }
    }
};

int main() {
    // vector<int> nums = {2, 4, 13, 8, 23, 0, 3, 65, 43, 4, 45, 99, 11, 23, 34};
    vector<int> nums;
    srand(time(nullptr));
    for (int i = 0; i < 1000000; ++i) {
        nums.emplace_back(rand());
    }

    MySort ms;
    auto startTime = chrono::steady_clock::now();

    // 千万数据  3.05s
    // sort(randNum.begin(), randNum.end());
    // 千万数据 4.65s
    // ms.quickSort(randNum, 0, randNum.size() - 1);
    ms.mergeSort(nums, 0, nums.size() - 1);
    auto currentTime = chrono::steady_clock::now();
    chrono::duration<double, milli> elapsed = currentTime - startTime;
    cout << "time: " << elapsed.count() / 1000 << "s";
    // for (int i : nums) {
    //     cout << i << " ";
    // }
    priority_queue<int> pq;
    return 0;
}