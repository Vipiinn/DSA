
class Solution {
public:

    bool isExists(TreeNode* root , TreeNode* target){
        if(root == NULL) return false;
        if(root == target) return true;
        return isExists(root->left,target) || isExists(root->right,target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == p || root == q) return root;
        else if(isExists(root->left,p) && isExists(root->right , q)) return root;
        else if(isExists(root->left,q) && isExists(root->right , p)) return root;
        else if(isExists(root->left,p) &&  isExists(root->left , q)) return lowestCommonAncestor(root->left , p , q);
        else{
            return lowestCommonAncestor(root->right , p , q);
        }
        
    }
};