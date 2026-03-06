#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr && curr->next) {
        struct ListNode* nextPair = curr->next->next;
        struct ListNode* second = curr->next;

        second->next = curr;
        curr->next = nextPair;

        if (prev) {
            prev->next = second;
        }

        prev = curr;
        curr = nextPair;
    }

    return newHead;
}