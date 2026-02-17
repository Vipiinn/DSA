
class Solution {
public:

    int findIdx(vector<int>& in , int data){
        for(int i=0;i<in.size();i++){
            if(in[i] == data) return i;
        }
        return -1;
    }

    TreeNode* bstFromPreIn(vector<int>& pre , vector<int>& in , int stIn , int endIn , int& preIdx){

        //base case
        if(stIn > endIn) return NULL;

        TreeNode* temp = new TreeNode(pre[preIdx]);
        preIdx++;

        int idx = findIdx(in , temp->val);

        temp->left = bstFromPreIn(pre,in,stIn,idx-1,preIdx);
        temp->right = bstFromPreIn(pre,in,idx+1,endIn,preIdx);

        return temp;

    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        vector<int>in(pre.begin() , pre.end());
        sort(in.begin() , in.end());

        int n = pre.size();

        int stIn = 0;
        int endIn = n-1;
        int preIdx = 0;

        return bstFromPreIn(pre,in,stIn,endIn,preIdx);
    }
};