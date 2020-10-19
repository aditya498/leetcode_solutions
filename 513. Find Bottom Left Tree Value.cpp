class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> pending;
        TreeNode* flag=NULL;
        pending.push(root);
        pending.push(flag);
        bool first=true;
        int element;
        while (pending.size()!=0){
            TreeNode* temp=pending.front();
            pending.pop();
            if(temp==NULL){
                if(pending.size()!=0)
                    pending.push(flag);
                first=true;
                continue;
            }
            if(first){
                element=temp->val;
                first= false;
            }
            if(temp->left!=NULL)
                pending.push(temp->left);
            if(temp->right!=NULL)
                pending.push(temp->right);
        }
        return element;
    }
};