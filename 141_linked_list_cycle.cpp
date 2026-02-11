/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* curr = head;

        while (curr)
        {
            if (curr->val == -1001) return true;

            curr->val = -1001;
            curr = curr->next;
        }

        return false;
    }
};
