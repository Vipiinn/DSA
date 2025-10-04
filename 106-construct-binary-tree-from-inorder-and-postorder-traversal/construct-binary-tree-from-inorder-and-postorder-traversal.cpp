
class Solution {
public:

    TreeNode* helper(vector<int>& post, int postLow, int postHi , vector<int>& in , int inLow , int inHi){
        if(postLow > postHi) return NULL;

        TreeNode* root = new TreeNode(post[postLow]);

        if(postLow == postHi) return root;

        int i = inLow;
        while(i <= inHi){
            if(in[i] == post[postLow]) break;
            i++;
        }
        int leftCount = i - inLow;
        int rightCount = inHi - i;

        root->right = helper(post, postLow+1, postLow+rightCount , in , i+1 , inHi);
        root->left = helper(post, postLow+rightCount+1, postHi , in , inLow , i-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = post.size();
        reverse(post.begin() , post.end());
        return helper(post , 0 , n-1 , in , 0 , n-1);
    }
};