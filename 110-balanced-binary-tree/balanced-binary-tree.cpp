
class Solution {
public:

    pair<bool,int>isBalancedFast(TreeNode* root){
        //base case
        if(root == NULL) return {true,0};

        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);

        bool diff = abs(left.second - right.second) <= 1;

        int height = max(left.second , right.second) + 1;

        pair<bool ,int> ans;
        if(left.first && right.first && diff) {
            ans = {true,height};
        }
        else {
            ans = {false , height};
        }

        return ans;
    }

    bool isBalanced(TreeNode* root) {

        return isBalancedFast(root).first;
    }
};