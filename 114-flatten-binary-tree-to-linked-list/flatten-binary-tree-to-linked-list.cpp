
class Solution {
public:

    vector<TreeNode*> preorderTraversal(TreeNode* root) {

        vector<TreeNode*>ans;

        stack<TreeNode*>st;
        st.push(root);
        while(st.size() > 0){
            TreeNode* temp = st.top();
            if(temp!=NULL) ans.push_back(temp);
            st.pop();

            if(temp!=NULL && temp->right != NULL) st.push(temp->right);
            if(temp!=NULL && temp->left != NULL) st.push(temp->left);
        }

        return ans;
    }
    
    void flatten(TreeNode* root) {

        vector<TreeNode*>ans = preorderTraversal(root);
        int n = ans.size();

        for(int i=0;i<n-1;i++){
            ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
        }
        
    }
};