class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        stack<vector<int>> rec;
        queue<TreeNode*> pending;
        pending.push(root);
        TreeNode* flag=new TreeNode(INT_MAX);
        pending.push(flag);
        vector<int> level;
        while (pending.size()!=0){
            TreeNode* temp=pending.front();
            pending.pop();
            if(temp->val==flag->val){
                rec.push(level);
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
        
        while (rec.size()!=0){
            ans.push_back(rec.top());
            rec.pop();
        }

        return ans;
    }
};