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
    ListNode* middleNode(ListNode* head) {
        // ListNode *temp=head;
        // int len=0;
        // while(temp!=NULL){
        //     temp=temp->next;
        //     len++;
        // }
        // int middleIndex=len/2;
        // int i=0;
        // temp=head;
        // while(i<middleIndex){
        //     temp=temp->next;
        //     i++;
        // }
        // return temp;
        
        
//         two pointer approach;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};