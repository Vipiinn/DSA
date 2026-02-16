
class Solution {
public:

    void Inorder(TreeNode* root , vector<int>& ans){
        if(root == NULL) return ;

        Inorder(root->left , ans);
        ans.push_back(root->val);
        Inorder(root->right , ans);
        
    }

    bool isValidBST(TreeNode* root) {
       
        vector<int> ans;

        Inorder(root,ans);

        int n = ans.size();
        for(int i=1;i<n;i++){
            if(ans[i-1] >= ans[i]) return false;
        }

        return true;
    }
};