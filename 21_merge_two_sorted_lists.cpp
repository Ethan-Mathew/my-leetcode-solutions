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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (!list1 || !list2)
        {
            return list1 ? list1 : list2;
        }

        ListNode* merged;
        ListNode* ptr1;
        ListNode* ptr2;

        if (list1->val <= list2->val)
        {
            merged = list1;
            ptr1 = list1->next;
            ptr2 = list2;
        }
        else
        {
            merged = list2;
            ptr1 = list1;
            ptr2 = list2->next;
        }

        ListNode* head = merged;

        while (true)
        {
            if (!ptr1 || !ptr2)
            {
                merged->next = ptr1 ? ptr1 : ptr2;
                return head;
            }

            if (ptr1->val <= ptr2->val)
            {
                merged->next = ptr1;
                merged = merged->next;
                ptr1 = ptr1->next;
            }
            else
            {
                merged->next = ptr2;
                merged = merged->next;
                ptr2 = ptr2->next;
            }
        }
    }
};