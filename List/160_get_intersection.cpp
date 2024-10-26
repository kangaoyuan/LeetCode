#include "../headers.h" // IWYU pragma: keep

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *begA = headA, *begB = headB;
        while(begA != begB){
            if(!begA)
                begA = headB;
            else
                begA = begA->next;

            if(!begB)
                begB = headA;
            else
                begB = begB->next;
        }
        return begA;
}

ListNode* getIntersectionNode_(ListNode* headA, ListNode* headB) {
    ListNode *A = headA, *B = headB;

    while(A && B){
        A = A->next;
        B = B->next;
    }

    if(!A){
        A = headB;
        while(B){
            A = A->next;
            B = B->next;
        }
        B = headA;
        while(A != B){
            A = A->next;
            B = B->next;
        }
        if(A == B)
            return A;
    } else {
        B = headA;
        while(A){
            A = A->next;
            B = B->next;
        }
        A = headB;
        while(A != B){
            A = A->next;
            B = B->next;
        }
        if(A == B)
            return A;
    }

    return nullptr;
}
