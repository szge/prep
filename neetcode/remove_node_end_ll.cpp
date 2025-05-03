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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we can use a solution with two pointers.
        // to start, send the second pointer n positions deep
        // then we can simultaneously move the first and second pointers
        // to get the nth position from the end
        // but actually we want the node before the one to delete
        // so let's create a dummy so first can start one position before
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = head;
        for (int pos = n; pos > 0; pos--) {
            second = second->next;
        }
        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }
        // now "first" is the node before the one we want to delete.
        ListNode* old_next = first->next;
        first->next = first->next->next;
        delete old_next;
        // we need to use dummy->next instead of head
        // in the case where head is deleted
        return dummy->next;
    }
};
