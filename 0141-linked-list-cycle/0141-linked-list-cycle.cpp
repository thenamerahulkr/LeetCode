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
    bool hasCycle(ListNode *head) {
        // if(head == NULL || head -> next == NULL){
        //     return false; 
        // }
        // ListNode *slow=head;
        // ListNode *fast=head;
        // while(fast!=NULL&&fast->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         return true;
        //     }
        // }
        // return false;
    // unordered_map<ListNode*, bool> visited;
    // while (head != NULL) {
    //     if (visited[head]==true) {
    //         return true; // Loop detected
    //     }
    //     visited[head] = true;
    //     head = head->next;
    // }
    
    // return false; // No loop
    unordered_set<ListNode*> s;
    ListNode * temp = head;
    while(temp){
        if(s.find(temp) != s.end()){
            return true;
        }
        s.insert(temp);
        temp = temp->next;
    }
    return false;
    }
};