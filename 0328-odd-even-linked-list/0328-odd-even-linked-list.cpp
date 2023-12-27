class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* odd  = head;
        ListNode* even = head -> next;
        ListNode *evenHead=head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
        
        // method 2
        // ListNode *evenHead=headhead->next;
        // vector<int>v;
        // while(odd!=NULL&&odd->next!=NULL){
        //     v.push_back(odd->val);
        //     odd=odd->next->next;
        // }
        // if(odd) v.push_back(odd->val);
        // while(even!=NULL&&even->next!=NULL){
        //     v.push_back(even->val);
        //     even=even->next->next;
        // }
        // if(even) v.push_back(even->val);
        // ListNode *temp=head;
        // int i=0;
        // while(i<v.size()){
        //     temp->val=v[i];
        //     temp=temp->next;
        //     i++;
        // }
        // return head;  
    }
};