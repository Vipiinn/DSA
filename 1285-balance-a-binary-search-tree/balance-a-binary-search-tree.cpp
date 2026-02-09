class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    
    TreeNode* buildBalancedBST(vector<int>& arr, int start, int end) {
        if (start > end) return NULL;
        
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left = buildBalancedBST(arr, start, mid - 1);
        root->right = buildBalancedBST(arr, mid + 1, end);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        
        return buildBalancedBST(arr, 0, arr.size() - 1);
    }
};
