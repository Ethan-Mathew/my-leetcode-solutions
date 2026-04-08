class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* upperListPtr = slow->next;
        slow->next = nullptr;
        ListNode* upperListPrev = nullptr;

        while (upperListPtr) {
            ListNode* temp = upperListPtr->next;
            upperListPtr->next = upperListPrev;
            upperListPrev = upperListPtr;
            upperListPtr = temp;
        }

        ListNode* upperHead = upperListPrev;
        ListNode* upperPtr = upperHead;
        ListNode* lowerPtr = head;

        ListNode* reordered = new ListNode(-1, nullptr);
        ListNode* reorderedPtr = reordered;

        while (upperPtr) {
            reorderedPtr->next = lowerPtr;
            lowerPtr = lowerPtr->next;
            reorderedPtr->next->next = upperPtr;
            upperPtr = upperPtr->next;
            reorderedPtr = reorderedPtr->next->next;
        }

        if (lowerPtr) {
            reorderedPtr->next = lowerPtr;
        }

        head = reordered->next;
    }
};