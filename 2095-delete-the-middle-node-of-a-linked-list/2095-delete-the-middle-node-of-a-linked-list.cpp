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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        // ListNode *slow=head;
        // ListNode *fast=head;
        // fast=fast->next->next;
        // // ListNode *temp=NULL;
        // while(fast!=NULL&&fast->next!=NULL){
        //     // temp=slow;
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // slow->next=slow->next->next;
        
//         using three pointer 
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *temp=NULL;
        while(fast!=NULL&&fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=temp->next->next;
        
        return head;
    }
};