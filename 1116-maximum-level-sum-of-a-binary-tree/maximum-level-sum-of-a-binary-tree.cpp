
class Solution {
public:

    int levelorder(TreeNode* root){

        queue<TreeNode*>q;
        q.push(root);

        int ans = 0;
        int lev = 0;
        int maxi = INT_MIN;
        

        while(q.size() > 0){
            int sum = 0;
            int level = q.size();
            for(int i=0;i<level;i++){
                TreeNode* temp = q.front();
                sum += temp->val;
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right); 
            }
            lev++;
            if(maxi < sum){
                maxi = sum;
                ans = lev;
            }
        }
        return ans;
    }

    int maxLevelSum(TreeNode* root) {
        return levelorder(root);
    }
};