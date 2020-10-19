class Pair{
public:
    int sum;
    int dif;
};

Pair helper(TreeNode* root){
    Pair ans;
    if(root==NULL){
        ans.sum=0;
        ans.dif=0;
        return ans;
    }

    Pair left=helper(root->left);
    Pair right=helper(root->right);

    ans.sum=root->val+left.sum+right.sum;
    ans.dif=abs(left.sum-right.sum)+left.dif+right.dif;

    return ans;
}

class Solution {
public:
    int findTilt(TreeNode* root) {
        return helper(root).dif;
    }
};