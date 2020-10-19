TreeNode* helper(TreeNode* root, int v, int d,bool left) {
    if(d==1){
        TreeNode* temp=new TreeNode(v);
        if(left)
            temp->left=root;
        else
            temp->right=root;
        return temp;
    }
    if(root==NULL)
        return NULL;
    root->left=helper(root->left,v,d-1,true);
    root->right=helper(root->right,v,d-1,false);
    return root;
}

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return helper(root,v,d,true);
    }
};