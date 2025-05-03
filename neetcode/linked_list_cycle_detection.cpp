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
    bool hasCycle(ListNode* head) {
        // idea 1: we could create an extended ListNode struct with a "visited" bool
        // idea 2: we could use an unordered set to keep track of visited nodes
        // idea 3: slow and fast pointer
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {
            if (fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            if (fast == slow) return true;
        }
    }
};
