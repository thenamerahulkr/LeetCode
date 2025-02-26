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
        // ListNode* temp = head;
        // int length = 0;
        // while(temp!= NULL){
        //     temp =  temp->next; // T.C => O(N)
        //     length++;
        // }
        // temp = head;
        // for(int i =1;i<=length/2;i++){
        //         temp = temp->next;      // T.C => O(N/2);
        // }
        // return temp;

        // slow and fast pointer => method 2
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL and fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};