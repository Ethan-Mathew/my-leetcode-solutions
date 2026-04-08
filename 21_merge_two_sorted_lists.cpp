class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1ptr = list1;
        ListNode* l2ptr = list2;
        ListNode* merged = new ListNode(-1, nullptr);
        ListNode* mergedPtr = merged;
        
        while (l1ptr && l2ptr) {
            if (l1ptr->val <= l2ptr->val) {
                mergedPtr->next = l1ptr;
                l1ptr = l1ptr->next;
            } else {
                mergedPtr->next = l2ptr;
                l2ptr = l2ptr->next;
            }

            mergedPtr = mergedPtr->next;
        }

        if (!l1ptr && l2ptr) {
            mergedPtr->next = l2ptr;
        } else {
            mergedPtr->next = l1ptr;
        }

        return merged->next;
    }
};