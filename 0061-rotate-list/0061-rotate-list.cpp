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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        
        // Compute length of list and get tail node
        ListNode* tail = head;
        int length = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }
        
        // Normalize k
        k = k % length;
        if (k == 0) {
            return head;
        }
        
        // Connect tail to head to make it circular
        tail->next = head;
        
        // Find the new tail: (length - k)th node
        // And set newHead = newTail->next
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        
        // Break the circle
        newTail->next = nullptr;
        
        return newHead;
    }
};