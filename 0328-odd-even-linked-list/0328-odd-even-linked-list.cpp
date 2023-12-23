class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* odd  = head;
        ListNode* even = head -> next;
        ListNode* evenhead = head -> next;
        
        while(even != NULL and even -> next != NULL){
            // put odd to the odd list
            odd ->next = odd -> next -> next;
            // Move the pointer to the next odd
            odd = odd -> next;
        
            // put even to the even list
            even -> next = even -> next -> next;
            // Move the pointer to the next even
            even = even -> next;
        }
        odd -> next = evenhead;
        return head;    
    }
};