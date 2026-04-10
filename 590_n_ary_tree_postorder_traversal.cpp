class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root) {
            postOrderRec(root);
            nodes.push_back(root->val);
        }

        return nodes;
    }

private:
    std::vector<int> nodes;

    void postOrderRec(Node* node) {
        if (!node) {
            return;
        }

        for (auto child : node->children) {
            postOrderRec(child);
            nodes.push_back(child->val);
        }
    }
};