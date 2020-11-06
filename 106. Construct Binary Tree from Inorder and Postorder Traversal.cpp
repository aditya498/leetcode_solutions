TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int is,int ie,int ps,int pe)
{
    if(is>ie)
        return NULL;

    int rootData=postorder[pe];
    int ri=-1;

    for(int i=is;i<=ie;i++)
    {
        if(inorder[i]==rootData)
        {
            ri=i;
            break;
        }
    }

    int lis=is;
    int lie=ri-1;
    int lps=ps;
    int lpe=lie-lis+lps;
    int ris=ri+1;
    int rie=ie;
    int rps=lpe+1;
    int rpe=pe-1;

    TreeNode* root=new TreeNode(rootData);
    root->left=helper(inorder,postorder,lis,lie,lps,lpe);
    root->right=helper(inorder,postorder,ris,rie,rps,rpe);

    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};