class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = 0;
        int lenB = 0;
        while (tempA or tempB) {
            if (tempA) {
                tempA = tempA->next;
                lenA++;
            }
            if (tempB) {
                lenB++;
                tempB = tempB->next;
            }
        }
        int difference = abs(lenA - lenB);
        tempA = headA;
        tempB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < difference; i++) {
                tempA = tempA->next;
            }
        } else {
            for (int i = 0; i < difference; i++) {
                tempB = tempB->next;
            }
        }
        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};