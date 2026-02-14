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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* init = new ListNode(0, head);
        ListNode* left = init;
        ListNode* right = head;

        while (right != nullptr)
        {
            if (right->val == val)
            {
                right = right->next;
                left->next = right;
            }
            else
            {
                right = right->next;
                left = left->next;
            }
        }

        return init->next;
    }
};