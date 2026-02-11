
// another approch using map 

class Solution {
public:
    TreeNode* constructTree(vector<int>& in , vector<int>& pre , int stIdx , int endIdx , int& preIdx,
                                map<int,int>& mp){
        //base case
        if(stIdx > endIdx) return NULL;

        TreeNode* temp = new TreeNode(pre[preIdx]);
        preIdx++;

        if(stIdx == endIdx) return temp;
        int idx = -1;
        if(mp.find(temp->val) != mp.end()){
            idx = mp[temp->val];
        }

        temp->left = constructTree(in,pre,stIdx,idx-1,preIdx,mp);
        temp->right = constructTree(in,pre,idx+1,endIdx,preIdx,mp);

        return temp;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        int n = pre.size();
        int stIdx = 0;
        int endIdx = n-1;
        int preIdx = 0;

        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }

        TreeNode* root = constructTree(in,pre,stIdx,endIdx,preIdx,mp);

        return root;
    }
};