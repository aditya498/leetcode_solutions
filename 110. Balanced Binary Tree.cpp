class Pair{
public:
    int height;
    bool balance;
};

Pair helper(TreeNode* root){
    if(root==NULL){
        Pair ans;
        ans.height=0;
        ans.balance= true;
        return ans;
    }

    Pair left=helper(root->left);
    Pair right=helper(root->right);
    Pair ans;
    ans.height=1+max(left.height,right.height);
    ans.balance=(abs(left.height-right.height)<=1) && left.balance && right.balance;
    return ans;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).balance;
    }
};