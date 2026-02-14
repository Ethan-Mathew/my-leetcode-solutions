class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length{1};
        ListNode* ptr = head;

        while (ptr) {
            ptr = ptr->next;
            if (ptr) length++;
        }

        int mid_index = length / 2;
        ptr = head;
        
        for (int i{}; i < mid_index; i++) {
            ptr = ptr->next;
        }
        
        return ptr;
    }
};