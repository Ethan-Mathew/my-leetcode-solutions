class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return nodes;
    }

private:
    std::vector<int> nodes;

    void postOrder(TreeNode* node) {
        if (!node) {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        nodes.push_back(node->val);
    }
};