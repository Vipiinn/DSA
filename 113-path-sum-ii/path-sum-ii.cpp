class Solution {
public:

    void helper(TreeNode* root , int targetSum , vector<vector<int>>&ans , vector<int>output){
        if(root == NULL) return;

        output.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == targetSum){
            ans.push_back(output);
            return;
        }

        
        helper(root->left , targetSum-root->val , ans , output);
        helper(root->right , targetSum-root->val , ans , output);
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>output;
        helper(root , targetSum , ans , output);
        return ans;
    }
};