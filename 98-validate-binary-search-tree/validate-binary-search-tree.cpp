
class Solution {
public:

    long long leftMax(TreeNode* root){
        if(root == NULL) return LLONG_MIN;
        return max((long long)(root->val) , max(leftMax(root->left) , leftMax(root->right)));
    }

    long long RightMin(TreeNode* root){
        if(root == NULL) return LLONG_MAX;
        return min((long long)(root->val) , min(RightMin(root->left) ,RightMin(root->right)));
    }

    bool isValidBST(TreeNode* root) {

        if(root == NULL) return true;
        
        if((leftMax(root->left) >= (long long)(root->val) || (RightMin(root->right) <= (long long)(root->val)))) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};