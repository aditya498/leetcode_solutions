class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> pending;
        TreeNode* flag=NULL;
        pending.push(root);
        pending.push(flag);
        int maxL=INT_MIN;
        while (pending.size()!=0){
            TreeNode* temp=pending.front();
            pending.pop();
            if(temp==NULL){
                if(pending.size()!=0)
                    pending.push(flag);
                ans.push_back(maxL);
                maxL=INT_MIN;
                continue;
            }
            maxL=max(maxL,temp->val);
            if(temp->left!=NULL)
                pending.push(temp->left);
            if(temp->right!=NULL)
                pending.push(temp->right);
        }
        return ans;
    }
};