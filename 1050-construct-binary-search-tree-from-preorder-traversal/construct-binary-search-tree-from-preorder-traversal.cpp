 // 3rd approch -> optimal approch
class Solution {
public:

    TreeNode* solve(vector<int>& pre , int mini , int maxi , int& idx){
        //basev case
        if(idx > pre.size()-1) return NULL;
        if(pre[idx] < mini || pre[idx] > maxi) return NULL;

        TreeNode* root = new TreeNode(pre[idx++]);

        root->left = solve(pre,mini,root->val,idx);
        root->right = solve(pre,root->val,maxi,idx);

        return root;
        
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        int mini = INT_MIN;
        int maxi = INT_MAX;

        int i = 0;

        return solve(pre,mini,maxi , i);
    }
};