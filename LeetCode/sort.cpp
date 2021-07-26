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
            // printNums(nums, cnt++);
            int idx = partition(nums, low, high);
            quickSort(nums, low, idx - 1);
            quickSort(nums, idx + 1, high);
        }
    };

private:
    void printNums(vector<int>& nums, int idx) {
        cout << "��" << idx << "����������" <<endl;
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
    // ǧ������  3.05s
    // sort(randNum.begin(), randNum.end());
    // ǧ������ 4.65s
    ms.quickSort(randNum, 0, randNum.size() - 1);
    auto currentTime = chrono::steady_clock::now();
    chrono::duration<double, milli> elapsed = currentTime - startTime;
    cout << "time: " << elapsed.count() / 1000 << "s";
    return 0;
}