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
        ListNode dummy(0);      // Dummy node for result list
        ListNode* curr = &dummy;
        int carry = 0;

        // Continue until both lists and carry are finished
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            // Add value from first list
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from second list
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;           // Carry for next digit
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy.next;
    }
};