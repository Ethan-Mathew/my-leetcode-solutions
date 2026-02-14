class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<int> vals;
        ListNode* ptr = head;

        while (ptr)
        {
            vals.push(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;

        while (ptr)
        {
            if (ptr->val != vals.top())
            {
                break;
            }
            else
            {
                ptr = ptr->next;
                vals.pop();
            }
        }

        return !ptr;
    }
};