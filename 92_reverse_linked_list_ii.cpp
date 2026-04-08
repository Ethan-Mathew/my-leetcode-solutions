class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == 1) return head;

        int count = 0;

        ListNode* plugPoint1 = new ListNode(-1, head);
        while (count < left - 1) {
            plugPoint1 = plugPoint1->next;
            count++;
        }

        ListNode* first = plugPoint1->next;
        ListNode* ptr = first->next;
        count += 2;

        ListNode* prev = first;

        while (count <= right) {
            ListNode* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
            count++;
        }

        ListNode* plugPoint2 = ptr;
        ListNode* last = prev;

        plugPoint1->next = last;
        first->next = plugPoint2;

        return (left == 1) ? plugPoint1->next : head;
    }
};