class Solution {
public:
    int pathSum(TreeNode* root, int sum,bool started=false) {
        if(root==NULL)
            return 0;
        int ans=0;
        if(!started){
            ans+=pathSum(root->left,sum,started);
            ans+=pathSum(root->right,sum,started);
        }
        int s=sum-root->val;
        if(s==0)
            ans++;
        ans+=pathSum(root->left,s,true);
        ans+=pathSum(root->right,s,true);
        return ans;
    }
};