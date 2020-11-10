class triplet{
public:
    int minV;
    int maxV;
    int dif;
};

triplet helper(TreeNode* root){
    triplet ans;
    ans.minV=root->val;
    ans.maxV=root->val;
    ans.dif=0;
    if(root->left!=NULL){
        triplet temp=helper(root->left);
        ans.minV=min(ans.minV,temp.minV);
        ans.maxV=max(ans.maxV,temp.maxV);
        ans.dif=max(max(temp.dif,ans.dif),max(abs(root->val-ans.minV),abs(root->val-ans.maxV)));
    }
    
    if(root->right!=NULL){
        triplet temp=helper(root->right);
        ans.minV=min(ans.minV,temp.minV);
        ans.maxV=max(ans.maxV,temp.maxV);
        ans.dif=max(max(temp.dif,ans.dif),max(abs(root->val-ans.minV),abs(root->val-ans.maxV)));
    }
    
    return ans;
}

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root).dif;
    }
};