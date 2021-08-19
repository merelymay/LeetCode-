#include "pub_head.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* p = dummyHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1) {
        p->next = l1;
    }
    if (l2) {
        p->next = l2;
    }
    return dummyHead->next;
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
    node3->next = nullptr;
    node4->next = node5;
    node5->next = nullptr;
    ListNode* node = mergeTwoList(node0, node4);
    while (node != nullptr) {
        cout<< node->val << endl;
        node = node->next;
    }
    return 0;
}