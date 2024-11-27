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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newhead = reverse(head->next);
        ListNode* temp = head->next;
        temp->next = head;
        head->next = NULL;
        return newhead;
    }

    void reorderList(ListNode* head) {
        ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        if(head == NULL || head->next == NULL) return;
        ListNode* curr = new ListNode(-1);
        ListNode* nex = curr;
        ListNode* prev = head;
        while(prev){
            ListNode* temp = new ListNode(prev->val);
            nex->next = temp;
            nex = nex->next;
            prev = prev->next;
        }
        curr = curr->next;
        ListNode* slow = curr;
        ListNode* fast = curr;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = curr;
        ListNode* second = reverse(slow->next);
        slow->next = NULL;
        ListNode* ptr = NULL;
        int count = 0;
        while(first != NULL && second != NULL){
            if(count % 2 == 0){
                ListNode* temp = new ListNode(first->val);
                temp->next = ptr;
                ptr = temp;
                count++;
                first = first->next;
            }
            else{
                ListNode* temp = new ListNode(second->val);
                temp->next = ptr;
                ptr = temp;
                count++;
                second = second->next;
            }
        }
        if(first){
            ListNode* temp = new ListNode(first->val);
            temp->next = ptr;
            ptr = temp;
        }
        if(second){
            ListNode* temp = new ListNode(second->val);
            temp->next = ptr;
            ptr = temp;
        }
        ptr = reverse(ptr);
        ListNode* a = head;
        while(a){
            a->val = ptr->val;
            a = a->next;
            ptr = ptr->next;
        }
    }
};