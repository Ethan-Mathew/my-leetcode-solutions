class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return nodes;
    }

private:
    std::vector<int> nodes;

    void inOrder(TreeNode* node) {
        if (!node) {
            return;
        }
        
        inOrder(node->left);
        nodes.push_back(node->val);
        inOrder(node->right);
    }
};