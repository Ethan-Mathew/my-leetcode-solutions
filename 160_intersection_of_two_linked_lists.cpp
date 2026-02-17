class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        std::unordered_set<ListNode*> nodesVisited;

        ListNode* ptrA = headA;
        while (ptrA) {
            nodesVisited.insert(ptrA);
            ptrA = ptrA->next;
        }

        ListNode* ptrB = headB;

        while (ptrB) {
            if (nodesVisited.find(ptrB) != nodesVisited.end()) {
                return ptrB;
            }

            ptrB = ptrB->next;
        }

        return nullptr;
    }
};