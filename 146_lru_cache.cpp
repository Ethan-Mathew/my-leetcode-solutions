class LRUCache {
public:
    LRUCache(int capacity)
        : maxSize{capacity}
    {
    }
    
    int get(int key) {
        if (keyNodePairs.find(key) != keyNodePairs.end()) {
            moveToFirst(keyNodePairs[key]);
            return keyNodePairs[key]->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (keyNodePairs.find(key) != keyNodePairs.end()) {
            keyNodePairs[key]->val = value;
            moveToFirst(keyNodePairs[key]);

        } else {
            Node* newNode = new Node(key, value);
            
            if (currentSize == 0) {
                first = newNode;
                last = newNode;
            } else {
                first->prev = newNode;
                newNode->next = first;
                first = newNode;
            }

            keyNodePairs[key] = newNode;

            if (currentSize == maxSize) {
                Node* newLast = last->prev;
                newLast->next = nullptr;

                keyNodePairs.erase(last->key);
                last = newLast;
                currentSize--;
            }

            currentSize++;
        }
    }

private:
    struct Node {
        Node* prev = nullptr;
        Node* next = nullptr;

        int key;
        int val;

        Node(int k, int v)
            : key{k}, val{v}
        {}
    };

    std::unordered_map<int, Node*> keyNodePairs;

    int currentSize = 0;
    int maxSize;

    Node* first = nullptr;
    Node* last = nullptr;

    void moveToFirst(Node* node) {
        if (node == first) {
            return;
        } else {
            Node* tempPrev = node->prev;

            if (tempPrev) {
                tempPrev->next = node->next;
            }

            if (node->next) {
                node->next->prev = tempPrev;
            }

            if (node == last && tempPrev) {
                last = tempPrev;
            }

            node->next = first;
            first->prev = node;
            node->prev = nullptr;
            first = node;
        }
    }
};