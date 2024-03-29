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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast =head;
        ListNode *first=head;
        ListNode *second =head;
        for(int i=1;i<k;i++){
            fast=fast->next;
        }
        first=fast;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        second=slow;
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        // ListNode *temp=head;
        // int len=1;
        // while(temp){
        //     len++;
        //     temp=temp->next;
        // }
        // temp=head;
        // for(int i=1;i<k;i++){
        //     temp=temp->next;
        // }
        // ListNode *ptr=head;
        // int kthLast=len-k;
        // for(int i=1;i<kthLast;i++){
        //     ptr=ptr->next;
        // }
        // int t=temp->val;
        // temp->val=ptr->val;
        // ptr->val=t;
        return head;
    }
};