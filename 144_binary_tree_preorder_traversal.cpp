class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return nodes;
    }

private:
    std::vector<int> nodes;

    void preOrder(TreeNode* node) {
        if (!node) {
            return;
        }

        nodes.push_back(node->val);
        preOrder(node->left);
        preOrder(node->right);
    }
};