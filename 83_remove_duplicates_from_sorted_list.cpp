class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next))
        {
            return head;
        }
        
        ListNode* temp = new ListNode(0, head);
        ListNode* left = temp;
        ListNode* right = head->next;
        ListNode* prev = head;

        while (right)
        {
            if (right->val == prev->val)
            {
                left->next = right;
            }
            else
            {
                left = left->next;
            }

            right = right->next;
            prev = prev->next;
        }

        return temp->next;
    }
};