
class Solution {
public:
    //without global variable
    void reverseInorder(TreeNode* root , int &sum){

        if(root == NULL) return;

        reverseInorder(root->right , sum);
    
        root->val += sum;
        sum = root->val;

        reverseInorder(root->left , sum);

    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInorder(root , sum);
        return root;
    }
};