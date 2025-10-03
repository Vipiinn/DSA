class Solution {
public:

    TreeNode* build(vector<int>& pre, int preLow, int preHi, vector<int>& in, int inLow , int inHi){

        if(preLow > preHi) return NULL;

        TreeNode* root = new TreeNode(pre[preLow]);
        if(preLow == preHi) return root;
        
        int i = inLow;
        while(i <= inHi){
            if(in[i] == pre[preLow]) break;
            i++;
        }

        int leftCount = i - inLow;
        int rightCount = inHi - i;

        root->left = build(pre , preLow+1 , preLow+leftCount , in , inLow , i-1);
        root->right = build(pre , preLow+leftCount+1 , preHi , in , i+1 , inHi);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        
        return build(pre , 0 , n-1 , in , 0 , n-1);

    }
};