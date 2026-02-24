
class Solution {
public:

    int BinaryToDecimal(string str){
        int ans = 0;
        int count = 0;

        for(int i=str.length()-1;i>=0;i--){
            if(str[i] == '1'){
                ans += pow(2,count);
            }
            count++;
        }

        return ans;
    }

    void solve(TreeNode* root , string str , vector<string>& ans){
        if(root == NULL) return ;

        str += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(str);
        }

        solve(root->left , str , ans);
        solve(root->right , str , ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        
        vector<string>ans;
        string str = "";

        solve(root , str , ans);

        int sum = 0;

        for(int i=0;i<ans.size();i++){
            sum += BinaryToDecimal(ans[i]);
        }

        return sum;

        

    }
};