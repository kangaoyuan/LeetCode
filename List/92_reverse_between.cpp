#include "../headers.h" // IWYU pragma: keep

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head, ListNode* end){
    ListNode *pre = nullptr, *cur = head;

    while(cur != end){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy_head = new ListNode(-1, head);
    ListNode *pre = dummy_head, *next = dummy_head;

    for (int i = 0; i < left - 1; ++i) {
        pre = pre->next;
    }

    for (int i = 0; i < right + 1; ++i) {
        next = next->next;
    }

    ListNode* reverse_start = pre->next;
    pre->next = reverseList(reverse_start, next);

    reverse_start->next = next;

    return dummy_head->next;
}
