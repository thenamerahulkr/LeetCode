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
        // int len=0;
        // ListNode *temp=head;
        // while(temp!=NULL){
        //     temp=temp->next;
        //     len++;
        // }
        // if(len==n){
        //     head=head->next;
        //     return head;
        // }
        // temp=head;
        // int index=len-n+1;
        // int i=1;
        // while(i<index){
        //     temp=temp->next;
        //     i++;
        // }
        // temp->next = temp->next->next
        ListNode *fast=head;
        ListNode *slow=head;
        int i =1;
        while(i<=n){
            fast=fast->next;
            i++;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};