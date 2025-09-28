
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //base case
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false;

        bool leftPart = isSameTree(p->left , q->left);
        if(leftPart == false) return false;

        bool rightPart = isSameTree(p->right , q->right);
        if(rightPart == false) return false;

        return true;

    }
};