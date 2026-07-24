class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;
        while (temp->next != nullptr) {
            if (st.count(temp->next->val)) {
                ListNode* duplicate = temp->next;
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        
        return dummy->next;
    }
};