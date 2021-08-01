#include "pub_head.h"
using namespace std;



class MySort {
public:
    /* ��������
    * ����˼�룺 ͨ��һ�����򽫴��ż�¼�ָ��ɶ����������֣�ʹ����һ���ּ�¼�Ĺؼ��־�������һ���ֵĹؼ���С��
    * �㷨������ ʱ�临�Ӷ� ������O(nlogn) ����(n^2) ƽ�����(nlogn)
    *           �ռ临�Ӷ� ������O(logn)  ����O(n)
    * �����ǲ��ȶ��㷨   ÿ��ѡ���Ļ�׼ֵΪ��ֵʱΪ����
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
    
    /* �鲢����
    * �鲢���� �ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨�����㷨�ǲ��÷��η���Divide and Conquer����һ���ǳ���
    * �͵�Ӧ�á��鲢������һ���ȶ������򷽷�����������������кϲ����õ���ȫ��������У�����ʹÿ������������
    * ��ʹ�����жμ������������������ϲ���һ���������Ϊ2-·�鲢��
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
        cout << "��" << idx << "����������" <<endl;
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

    // ǧ������  3.05s
    // sort(randNum.begin(), randNum.end());
    // ǧ������ 4.65s
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