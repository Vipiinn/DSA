class Solution {
public:

    TreeNode* build(vector<int>& nums , int st , int end){

        if(st > end) return 0;
        
        int mid = st + (end-st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums , st , mid-1);
        root->right = build(nums , mid+1 , end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        return build(nums , st , end);
    }
};