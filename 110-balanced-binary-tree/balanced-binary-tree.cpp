class Solution {
public:
    bool balanced = true;

    int height(TreeNode* root) {

        if (root == NULL)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1) {
            balanced = false;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        height(root);

        return balanced;
    }
};