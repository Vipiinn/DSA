
class Solution {
public:

    int height(TreeNode* root){
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left , right) + 1;
    }

    pair<int,int>Fast(TreeNode* root){
        if(root == NULL) return {0 , 0};

        pair<int,int> left = Fast(root->left);
        pair<int,int> right = Fast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int>ans;
        ans.first = max(op1 , max(op2,op3));
        ans.second = max(left.second , right.second) + 1;

        return ans;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        return Fast(root).first - 1;
    }
};