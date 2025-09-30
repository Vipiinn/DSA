
class Solution {
public:

    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }

    void nthOrder(TreeNode* root, int curr, int level, vector<int>& v) {
    if(root == NULL) return;

    if(curr == level) {
        v.push_back(root->val);
        return; // stop here
    }

    if(level % 2 == 0) { // even level → right to left
        nthOrder(root->right, curr+1, level, v);
        nthOrder(root->left, curr+1, level, v);
    } else {             // odd level → left to right
        nthOrder(root->left, curr+1, level, v);
        nthOrder(root->right, curr+1, level, v);
    }
}


    void levelOrder(TreeNode* root , vector<vector<int>>&ans){
        int n = levels(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            nthOrder(root,1,i,v);
            ans.push_back(v);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levelOrder(root , ans);
        return ans;
    }
};