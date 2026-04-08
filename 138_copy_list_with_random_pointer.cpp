class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> oldToNewMap;

        Node* oldListPtr = head;
        Node* newListBase = new Node(-101);

        Node* newListPtr = newListBase;

        while (oldListPtr) {
            newListPtr->next = new Node(oldListPtr->val);
            newListPtr = newListPtr->next;

            oldToNewMap[oldListPtr] = newListPtr;

            oldListPtr = oldListPtr->next;
        }

        oldListPtr = head;
        newListPtr = newListBase->next;

        while (oldListPtr) {
            newListPtr->random = oldToNewMap[oldListPtr->random];
            
            newListPtr = newListPtr->next;
            oldListPtr = oldListPtr->next;
        }

        return newListBase->next;
    }
};