
class Solution {
public:

    void Inorder(TreeNode* root , vector<int>& ans){

        if(root == NULL){
            return;
        }

        Inorder(root->left , ans);
        ans.push_back(root->val);
        Inorder(root->right , ans);

    }

    bool findTarget(TreeNode* root, int k) {
        
        vector<int>in;
        Inorder(root , in);

        int i = 0;
        int j = in.size()-1;

        while(i < j){
            int sum = in[i] + in[j];
            if(sum == k) return true;
            else if(sum > k){
                j--;
            }
            else{
                i++;
            }
        }

        return false;
    }
};