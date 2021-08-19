#include "pub_head.h"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

// 头插法
ListNode* reverseList(ListNode* head) {
    ListNode* dummyHead = new ListNode(0);
    while (head) {
        ListNode* tmp = head->next;
        head->next = dummyHead->next;
        dummyHead->next = head;
        head = tmp;
    }
    return dummyHead->next;
}

// 翻转法
ListNode* reverseList1(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main() {
    ListNode* node0 = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;
    ListNode* node = reverseList1(node0);
    while (node != nullptr) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}