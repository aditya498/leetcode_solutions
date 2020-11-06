TreeNode* helper(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie)
{
    if(ps>pe)
        return NULL;

    int r=-1;
    for(int i=is;i<=ie;i++)
    {
        if(inorder[i]==preorder[ps])
        {
            r=i;
            break;
        }
    }

    int pls=ps+1;
    int ils=is;
    int ile=r-1;
    int ple=ile-ils+pls;
    int prs=ple+1;
    int pre=pe;
    int irs=r+1;
    int ire=ie;

    TreeNode* root=new TreeNode(preorder[ps]);
    root->left=helper(preorder,pls,ple,inorder,ils,ile);
    root->right=helper(preorder,prs,pre,inorder,irs,ire);

    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};