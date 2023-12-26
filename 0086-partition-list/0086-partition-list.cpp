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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *rightPart=new ListNode(0);
        ListNode *leftPart=new ListNode(0);
        ListNode *leftTail=leftPart;
        ListNode *rightTail=rightPart;
        ListNode *temp=head;
        while(temp){
            if(temp->val<x){
                leftTail->next=temp;
                leftTail=leftTail->next;
            }
            else{
                 rightTail->next=temp;
                rightTail=rightTail->next;
            }
            temp=temp->next;   
        }
        leftTail->next=rightPart->next;
        rightTail->next=NULL;
        return leftPart->next;
        // vector<int> v;
        // ListNode *temp=head;
        // while(temp!=NULL){
        //     if(temp->val<x){
        //         v.push_back(temp->val);
        //         temp=temp->next;
        //     }
        // }
        // while(temp!=NULL){
        //     if(temp->val>x){
        //         v.push_back(temp->val);
        //         temp=temp->next;
        //     }
        // }
        // temp=head;
        // int i=0;
        // while(temp){
        //     temp->val=v[i];
        //         temp=temp->next;
        //     i++;
        // }
        // return head;
    }
};