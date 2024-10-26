#include "../headers.h" // IWYU pragma: keep

struct ListNode {
    int val;
    ListNode *next;
};

ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next)
        return head;

    ListNode* sec_elem = head->next;
    ListNode* next_it = head->next->next;
    head->next->next = head;
    head->next = swapPairs(next_it);

    return sec_elem;
}
