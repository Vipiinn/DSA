
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;

        bool left = isSameTree(p->left , q->left);
        bool right = isSameTree(p->right , q->right);

        if(left && right && p->val == q->val) return true;
        else return false;
    }
};