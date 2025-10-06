
class Solution {
public:

    void preorder(TreeNode* root , vector<int>&ans){
        if(root == NULL) return;

        preorder(root->left , ans);
        ans.push_back(root->val);
        preorder(root->right , ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        preorder(root , ans);
        for(int i=1;i<ans.size();i++){
            if(ans[i-1] >= ans[i]) return false;
        }

        return true;
    }
};