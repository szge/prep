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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* curr = sum;
        while (l1 != nullptr || l2 != nullptr) {
            int l1_val = (l1 == nullptr) ? 0 : l1->val;
            int l2_val = (l2 == nullptr) ? 0 : l2->val;
            int curr_sum = l1_val + l2_val + curr->val;
            curr->val = curr_sum % 10;
            int carryover = curr_sum / 10;
            if (carryover > 0 || (l1 != nullptr && l1->next != nullptr) || (l2 != nullptr && l2->next != nullptr)) {
                // create a new node if there is still more to process
                curr->next = new ListNode(carryover);
            }
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            curr = curr->next;
        }
        return sum;
    }
};
