TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL)
        return NULL;
    if(p->val<=root->val && root->val<=q->val)
        return root;
    if(p->val<root->val)
        return helper(root->left,p,q);
    if(p->val>root->val)
        return helper(root->right,p,q);
    return NULL;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            TreeNode* temp=p;
            p=q;
            q=temp;
        }
        
        return helper(root,p,q);
    }
};
