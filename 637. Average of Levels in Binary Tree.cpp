class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==NULL)
            return ans;
        TreeNode* flag=NULL;
        queue<TreeNode*> pending;
        pending.push(root);
        pending.push(flag);
        double sum=0;
        int num=0;
        while(pending.size()!=0){
            TreeNode* temp=pending.front();
            pending.pop();
            if(temp==NULL){
                if(pending.size()!=0)
                    pending.push(flag);
                ans.push_back(sum/num);
                sum=0;
                num=0;
                continue;
            }
            
            if(temp->left!=NULL)
                pending.push(temp->left);
            if(temp->right!=NULL)
                pending.push(temp->right);
            num++;
            sum+=temp->val;
        }
        return ans;
    }
};
