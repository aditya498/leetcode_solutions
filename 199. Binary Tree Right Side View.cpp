class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> pending;
        pending.push(root);
        TreeNode* flag=new TreeNode(INT_MAX);
        pending.push(flag);
        vector<int> level;
        while (pending.size()!=0){
            TreeNode* temp=pending.front();
            pending.pop();
            if(temp->val==flag->val){
                ans.push_back(level.at(level.size()-1));
                while (level.size()!=0)
                    level.pop_back();
                if(pending.size()!=0)
                    pending.push(flag);
                continue;
            }
            level.push_back(temp->val);
            if(temp->left!=NULL)
                pending.push(temp->left);
            if(temp->right!=NULL)
                pending.push(temp->right);
        }
        return ans;
    }
};