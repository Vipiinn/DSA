
class Solution {
public:

    int findIdx(vector<int>& in , int val){
        for(int i=0;i<in.size();i++){
            if(in[i] == val) return i;
        }

        return -1;
    }

    TreeNode* constructTree(vector<int>& in , vector<int>& pre , int stIdx , int endIdx , int& preIdx){
        //base case
        if(stIdx > endIdx) return NULL;

        TreeNode* temp = new TreeNode(pre[preIdx]);
        preIdx++;

        if(stIdx == endIdx) return temp;
        int idx = findIdx(in,temp->val);

        temp->left = constructTree(in,pre,stIdx,idx-1,preIdx);
        temp->right = constructTree(in,pre,idx+1,endIdx,preIdx);

        return temp;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        int n = pre.size();
        int stIdx = 0;
        int endIdx = n-1;
        int preIdx = 0;

        TreeNode* root = constructTree(in,pre,stIdx,endIdx,preIdx);

        return root;
    }
};