#include "pub_head.h"
using namespace std;



class MySort {
public:
    /* ????????
    * ??????? ???????????????????????????????????????????????????????????????????ß≥??
    * ???????? ??¡Ÿ??? ??????O(nlogn) ?????(n^2) ??????(nlogn)
    *           ??¡Ÿ??? ??????O(logn)  ?????O(n)
    * ????????????   ??????????????????????
    */
    void quickSort(vector<int>& nums, int low, int high) {
        // static int cnt = 0;
        if (low < high) {
            // printNums(nums, cnt++);
            int idx = partition(nums, low, high);
            quickSort(nums, low, idx - 1);
            quickSort(nums, idx + 1, high);
        }
    };
    
    /* ?ˆ„????
    * ?ˆ„???? ???????ˆ„????????????ßπ??????????????????°¬??¶«???Divide and Conquer????????????
    * ?????®¢??ˆ„???????????????????????????????????ß‹??????????????????ßµ???????????????????
    * ????????ßÿ¶Ã????????????????????????????????????2-°§?ˆ„??
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

//-------------------------------------------------------------------------
    void adjustHeap(vector<int>& nums, int i, int len) {
        int tmp = nums[i];
        for (int k = 2*i + 1; k < len; k = 2*k + 1) {
            if (k+1 < len && nums[k] < nums[k+1]) {
                k++;
            }
            if (nums[k] > tmp) {
                nums[i] = nums[k];
                i = k;
            }
        }
        nums[i] = tmp;
    }

    // ∂—≈≈–Ú
    void heapSort(vector<int>& nums) {
        int len = nums.size();
        for (int i = len/2 - 1; i >= 0; i--) {
            adjustHeap(nums, i, len);
        }
        for (int i = len-1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            adjustHeap(nums, 0, i);
        }
    }

//-------------------------------------------------------------------------
    
private:
    void printNums(vector<int>& nums, int idx) {
        cout << "??" << idx << "??????????" <<endl;
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
    for (int i = 0; i < 10000000; ++i) {
        nums.emplace_back(rand());
    }

    MySort ms;
    auto startTime = chrono::steady_clock::now();

    // ???????  3.05s
    // sort(randNum.begin(), randNum.end());
    // ??????? 4.65s
    // ms.quickSort(nums, 0, nums.size() - 1);
    // ms.mergeSort(nums, 0, nums.size() - 1);
    ms.heapSort(nums);
    auto currentTime = chrono::steady_clock::now();
    chrono::duration<double, milli> elapsed = currentTime - startTime;
    cout << "time: " << elapsed.count() / 1000 << "s";
    // for (int i : nums) {
    //     cout << i << " ";
    // }
    return 0;
}