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
    // attempt 1: use a stack to keep track of values.
    // ListNode* reverseList(ListNode* head) {
    //     if (head == nullptr || head->next == nullptr) return head;
    //     stack<int> s;
    //     ListNode* curr = head;
    //     while (curr != nullptr) {
    //         s.push(curr->val);
    //         curr = curr->next;
    //     }
    //     ListNode* new_head = new ListNode(s.top());
    //     curr = new_head;
    //     s.pop();
    //     while (s.size() > 0) {
    //         ListNode* next = new ListNode(s.top());
    //         curr->next = next;
    //         curr = next;
    //         s.pop();
    //     }
    //     return new_head;
    // }
    // attempt 2: simply update the direction of next as I traverse the LL
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* old_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = old_next;
        }
        return prev;
    }
};
