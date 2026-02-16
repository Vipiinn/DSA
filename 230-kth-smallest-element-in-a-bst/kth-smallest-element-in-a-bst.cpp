
class Solution {
public:

    int solve(TreeNode* root , int &i , int k){
        if(root == NULL) return -1;

        //left
        int left = solve(root->left , i , k);
        if(left != -1) return left;

        //root
        i++;
        if(i == k) return root->val;

        //right;
        return solve(root->right , i , k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return solve(root , i , k);
    }
};