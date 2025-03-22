/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     inta vl;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
       int x = node->val;
       int y = node->next->val;
       node->val = y;
       node->next->val = x;
       node->next= node->next->next;
    }
};