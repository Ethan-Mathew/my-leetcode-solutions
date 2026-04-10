class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int treeHeight = height(root);

        return std::max(treeHeight, maxWidth);
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight = 0;
        if (root->left) {
            leftHeight =  1 + height(root->left);
        }

        int rightHeight = 0;
        if (root->right) {
            rightHeight = 1 + height(root->right);
        }

        maxWidth = std::max(maxWidth, leftHeight + rightHeight);
        return std::max(leftHeight, rightHeight);
    }

    int maxWidth = 0;
};