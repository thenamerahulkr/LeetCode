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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* c = dummy;
        ListNode* a = list1;
        ListNode* b = list2;
        while(a != nullptr and b != nullptr){
            if(a->val <= b->val){
                c->next = a;
                a = a->next;
                c = c->next;
            }
            else{
                c->next = b;
                b = b->next;
                c = c->next;
            }
        }
        if(a == nullptr) c->next = b;
        else c->next = a;
        return dummy->next;
    }
};