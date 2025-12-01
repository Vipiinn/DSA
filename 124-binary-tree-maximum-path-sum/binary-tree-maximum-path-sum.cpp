
class Solution {
public:

    int maximumPath(TreeNode* root , int& maxi){
        //base case
        if(root == NULL) return 0;

        int left = max(0,maximumPath(root->left , maxi));
        int right = max(0,maximumPath(root->right , maxi));

        maxi = max(maxi , left+right+root->val);

        return max(left,right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maximumPath(root,maxi);
        return maxi;
    }
};