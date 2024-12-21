/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

int getlength(ListNode* head) {
    int len = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return NULL; // LL is empty
        int len = getlength(head);
        if (k > len) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        int count = 0;

        while (count < k) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if (forward != NULL) {
            // still nodes are left
            head->next = reverseKGroup(forward, k);
        }

        return prev;
    }
};