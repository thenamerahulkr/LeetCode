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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow != nullptr) {
            st.push(slow->val);
            slow = slow->next;
        }
        ListNode* curr = head;
        int max_value_twins = INT_MIN;
        while (!st.empty()) {
            max_value_twins = max(max_value_twins, curr->val + st.top());
            st.pop();
            curr = curr->next;
        }

        return max_value_twins;
    }
};