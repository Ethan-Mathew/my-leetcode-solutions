class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* l1Ptr = l1;
        ListNode* l2Ptr = l2;
        ListNode* newListBase = new ListNode(0, nullptr);
        ListNode* newListPtr = newListBase;

        while (l1Ptr && l2Ptr) {
            int sum = l1Ptr->val + l2Ptr->val + carry;

            newListPtr->next = new ListNode(sum % 10);

            carry = (sum > 9) ? 1 : 0;

            newListPtr = newListPtr->next;
            l1Ptr = l1Ptr->next;
            l2Ptr = l2Ptr->next;
        }

        ListNode* remaining = (l1Ptr) ? l1Ptr : l2Ptr;

        while (remaining) {
            int sum = remaining->val + carry;

            newListPtr->next = new ListNode(sum % 10);
            carry = (sum > 9) ? 1 : 0;

            remaining = remaining->next;
            newListPtr = newListPtr->next;
        }

        if (carry) newListPtr->next = new ListNode(1);

        return newListBase->next;
    }
};