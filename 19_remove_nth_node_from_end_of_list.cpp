class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0, head);
        ListNode* right = head;
        ListNode* left = temp;

        int rightMoves = 0;
        while (right != nullptr) {
            right = right->next;
            rightMoves++;
        }

        int leftMoves = rightMoves - n;
        for (int i{}; i < leftMoves; i++) {
            left = left->next;
        }

        left->next = left->next->next;

        return temp->next;
    }
};