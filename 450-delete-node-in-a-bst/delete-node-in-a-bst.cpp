class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        else {

            // Case 1: No left child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: No right child
            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* temp = findMin(root->right);

            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }

private:

    TreeNode* findMin(TreeNode* root) {

        while (root->left != NULL) {
            root = root->left;
        }

        return root;
    }
};