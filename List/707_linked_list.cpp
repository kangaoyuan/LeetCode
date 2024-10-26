#include "../headers.h" // IWYU pragma: keep

class MyLinkedList {
    struct LinkNode {
        int              val;
        struct LinkNode* next;
    };

    LinkNode* head;

    MyLinkedList() {
        head = new LinkNode(0, NULL);
    }

    int get(int index) {
        if (index < 0)
            return -1;
        LinkNode* cur = head->next;
        for (int i = 0; i < index; ++i) {
            if (!cur)
                return -1;
            cur = cur->next;
        }
        if (!cur)
            return -1;
        return cur->val;
    }

    void addAtHead(int val) {
        LinkNode* node = new LinkNode(val, head->next);
        head->next = node;
    }

    void addAtTail(int val) {
        LinkNode *pre = head, *cur = head->next;
        LinkNode* node = new LinkNode(val, NULL);
        while (cur) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = node;
    }

    void addAtIndex(int index, int val) {
        if (index < 0)
            return;
        LinkNode *pre = head, *cur = head->next;
        LinkNode* node = new LinkNode(val, NULL);

        int nums = 0;
        for (LinkNode* elem = cur; elem; elem = elem->next)
            nums++;
        if (index > nums)
            return;

        for (int i = 0; i < index; ++i) {
            if (!cur)
                break;
            pre = cur;
            cur = cur->next;
        }
        pre->next = node;
        node->next = cur;
        return;
    }

    void deleteAtIndex(int index) {
        if (index < 0)
            return;
        LinkNode *pre = head, *cur = head->next;
        for (int i = 0; i < index; ++i) {
            if (!cur)
                return;
            pre = cur;
            cur = cur->next;
        }
        if (!cur)
            return;
        pre->next = cur->next;
        return;
    }
};
