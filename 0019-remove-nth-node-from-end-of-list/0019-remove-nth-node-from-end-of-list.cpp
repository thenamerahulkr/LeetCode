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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            len++;
        }
        int idx = len-n;
        if(len == n){
            return head->next;
        }
        temp = head;
        for(int i =1; i<idx; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};