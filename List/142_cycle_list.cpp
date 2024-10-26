#include "../headers.h" // IWYU pragma: keep

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    if(!fast || !fast->next)
        return nullptr;

    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
