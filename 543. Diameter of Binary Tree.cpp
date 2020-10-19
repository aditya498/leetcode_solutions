class Pair{
public:
    int height;
    int diameter;
};

Pair helper(TreeNode* root){
    if(root==NULL){
        Pair ans;
        ans.height=0;
        ans.diameter=0;
        return ans;
    }

    Pair left=helper(root->left);
    Pair right=helper(root->right);
    Pair ans;
    ans.height=1+max(left.height,right.height);
    ans.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return ans;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).diameter;
    }
};