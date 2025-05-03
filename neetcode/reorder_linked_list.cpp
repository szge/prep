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
private:
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
public:
    void reorderList(ListNode* head) {
        // it's a singly linked list
        // 1. split the list in half
        // 2. reverse the second half
        // 3. stitch the linked list back together
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // now slow is the middle of the LL
        ListNode* first = head;
        ListNode* second = reverseList(slow);
        while (first != nullptr && second != nullptr) {
            ListNode* first_next = first->next;
            ListNode* second_next = second->next;
            first->next = second;
            second->next = first_next;
            first = first_next;
            second = second_next;
        }
    }
};
