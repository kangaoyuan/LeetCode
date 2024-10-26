#include "../headers.h" // IWYU pragma: keep

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0, head);
    ListNode *pre = dummy, *cur = head;

    while (cur) {
        if (cur->val == val) {
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }

    return dummy->next;
}
