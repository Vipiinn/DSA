
class Solution {
public:

    void Inorder(TreeNode* root , vector<int>& ans){
        //base case;
        if(root == NULL) return ;

        Inorder(root->left , ans);
        ans.push_back(root->val);
        Inorder(root->right , ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int>ans;

        Inorder(root , ans);

        return ans[k-1];
    }
};