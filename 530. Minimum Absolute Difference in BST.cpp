/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Pair{
public:
    int ans;
    int minV;
    int maxV;
};

Pair helper(TreeNode* root){
    if(root==NULL){
        Pair ans;
        ans.ans=INT_MAX;
        ans.maxV=INT_MIN;
        ans.minV=INT_MAX;
        return ans;
    }
    Pair left=helper(root->left);
    Pair right=helper(root->right);
    Pair ans;
    ans.ans=min(left.ans,right.ans);
    if(left.maxV!=INT_MIN)
        ans.ans=min(ans.ans,abs(root->val-left.maxV));
    if(right.minV!=INT_MAX)
        ans.ans=min(ans.ans,abs(right.minV-root->val));
    ans.minV=min(root->val,min(left.minV,right.minV));
    ans.maxV=max(root->val,max(left.maxV,right.maxV));
    return ans;
}

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        return helper(root).ans;
    }
};