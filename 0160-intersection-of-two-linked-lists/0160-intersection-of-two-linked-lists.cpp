/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA=headA;
        ListNode *tempB=headB;
        int lenA=0;
        int lenB=0;
        while(tempA!=NULL){
            tempA=tempA->next;
            lenA++;
        }
        while(tempB!=NULL){
            tempB=tempB->next;
            lenB++;
        }
        tempA=headA;
        tempB=headB;
        int diff=lenA-lenB;
        if(lenA>lenB){
            for(int i=1;i<=diff;i++){
                tempA=tempA->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
//         if lenB>=lenA
        else{
            int diff=lenB-lenA;
            for(int i=1;i<=diff;i++){
                tempB=tempB->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
    }
};