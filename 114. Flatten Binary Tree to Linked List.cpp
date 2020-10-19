class Pair{
public:
    TreeNode* start;
    TreeNode* end;
};

Pair helper(TreeNode* root){
    if(root==NULL){
        Pair ans;
        ans.start=NULL;
        ans.end=NULL;
        return ans;
    }

    Pair left=helper(root->left);
    Pair right=helper(root->right);
    Pair ans;
    ans.start=root;
    ans.end=root;
    if(left.start!=NULL){
        ans.start->right=left.start;
        ans.end=left.end;
    }
    
    if(right.start!=NULL){
        ans.end->right=right.start;
        ans.end=right.end;
    }
    root->left=NULL;
    return ans;
}

class Solution {
public:
    void flatten(TreeNode* root) {
        Pair temp=helper(root);
    }
};