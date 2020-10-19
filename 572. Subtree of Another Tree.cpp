class Solution {
public:
    bool isSubtree(TreeNode* root1, TreeNode* root2,bool started=false) {
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL || root2==NULL)
            return false;
        if(started){
            if(root1->val==root2->val){
                if(isSubtree(root1->left,root2->left,true) && isSubtree(root1->right,root2->right,true))
                    return true;
            }
            return false;
        }
        if(root1->val==root2->val){
            if(isSubtree(root1->left,root2->left,true) && isSubtree(root1->right,root2->right,true))
                return true;
        }
        return isSubtree(root1->left,root2,false) || isSubtree(root1->right,root2,false);
    }
};