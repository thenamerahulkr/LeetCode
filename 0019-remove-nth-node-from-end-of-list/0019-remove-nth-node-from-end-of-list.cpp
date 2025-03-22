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
        if(head==NULL || head->next==NULL){
            return head->next;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        for(int i=1; i<=n; i++){
            fast = fast->next;
        }
        if(!fast){
            return head->next;
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next=slow->next->next;
        // delete slow->next;
        // ListNode * temp = head;
        // int l = 0;
        // while(temp!=NULL){
        //     temp=temp->next;
        //     l++;
        // }
        // if(l==n) return head->next;
        // temp = head;
        // for(int i=1; i<l-n; i++){
        //     temp = temp->next;
        // }
        // temp->next= temp->next->next;
        return head;
    }
};