#include "../headers.h" // IWYU pragma: keep

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy_head = new ListNode(-1, head);

    ListNode *slow = dummy_head, *fast= dummy_head;
    for(int i = 0; i < n; ++i){
        fast = fast->next;
        if(!fast)
            return nullptr;
    }

    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy_head->next;
}

ListNode* removeNthFromEnd_(ListNode* head, int n) {
    ListNode* dummy_head = new ListNode(-1, head);

    ListNode *slow = dummy_head, *fast = dummy_head;
    while (n && fast) {
        n--;
        fast = fast->next;
    }
    if (!fast)
        return nullptr;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy_head->next;
}

ListNode* removeNthFromEnd__(ListNode* head, int n) {
    ListNode *slow = head, *fast = head;
    while (n && fast) {
        n--;
        fast = fast->next;
    }

    if (!fast && n)
        return nullptr;
    if (!fast && !n)
        return head->next;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return head;
}
