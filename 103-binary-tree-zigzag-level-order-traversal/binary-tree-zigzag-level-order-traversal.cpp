
class Solution {
public:

    void levelOrder(TreeNode* root,vector<int>output,vector<vector<int>>&ans){
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;

        while(q.size() > 0){
            int level = q.size();
            for(int i=0;i<level;i++){
                TreeNode* temp = q.front();
                output.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flag == true){
                ans.push_back(output);
                flag = false;
            }
            else{
                reverse(output.begin(),output.end());
                ans.push_back(output);
                flag = true;
            }
            output.clear(); 
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int>output;
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        levelOrder(root,output,ans);
        return ans;
    }
};