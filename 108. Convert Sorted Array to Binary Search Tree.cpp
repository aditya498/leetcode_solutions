TreeNode* helper(vector<int>& nums,int s,int e){
    if(s>e)
        return NULL;
    int m=(s+e)/2;
    TreeNode* root=new TreeNode(nums[m]);
    root->left=helper(nums,s,m-1);
    root->right=helper(nums,m+1,e);
    return root;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};