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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp=head;
        ListNode *Dummy=new ListNode(-1);
        ListNode *mover=Dummy;
        int sum=0;
        while(temp!=NULL){
            while(temp!=NULL&&temp->val==0){
                temp=temp->next;
            }
            while(temp!=NULL&&temp->val!=0){
                sum=sum+temp->val;
                temp=temp->next;
            }
            if(sum!=0){
                ListNode *newNode =new ListNode(sum);
                mover->next=newNode;
                mover=mover->next;
                sum=0;
            }
          }
        return Dummy->next;
        }
};