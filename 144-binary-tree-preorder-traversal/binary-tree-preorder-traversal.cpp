
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int>ans;

        stack<TreeNode*>st;
        st.push(root);
        while(st.size() > 0){
            TreeNode* temp = st.top();
            if(temp!=NULL) ans.push_back(temp->val);
            st.pop();

            if(temp!=NULL && temp->right != NULL) st.push(temp->right);
            if(temp!=NULL && temp->left != NULL) st.push(temp->left);
        }

        return ans;
    }
};