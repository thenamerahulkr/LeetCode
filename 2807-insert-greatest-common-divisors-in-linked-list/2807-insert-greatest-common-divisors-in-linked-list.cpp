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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        while(ptr2 != nullptr){
            int num1 = ptr1->val;
            int num2 = ptr2->val;
            int gcd_of_two = gcd(num1, num2);
            ListNode* new_node = new ListNode(gcd_of_two);
            ptr1->next = new_node;
            new_node->next = ptr2;
            ptr1 = ptr1->next->next;
            ptr2 = ptr2->next;
        }
        return head;
    }
};