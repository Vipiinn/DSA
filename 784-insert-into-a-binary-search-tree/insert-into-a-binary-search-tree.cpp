
class Solution {
public:

    void helper(TreeNode* root, int val){

        if(root == NULL) return;

        if(root->val > val){
            if(root->left == NULL) root->left = new TreeNode(val);
            else helper(root->left , val);
        }
        else{
            if(root->right == NULL) root->right = new TreeNode(val);
            else helper(root->right , val);
        }

       
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        helper(root , val);
        return root;
    }
};