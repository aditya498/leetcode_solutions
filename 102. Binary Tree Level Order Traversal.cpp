/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> pending;
        TreeNode* flag=new TreeNode(INT_MAX);
        pending.push(root);
        pending.push(flag);
        vector<int> level;
        while (pending.size()!=0){
            TreeNode* temp=pending.front();
            pending.pop();
            if(temp->val==flag->val){
                ans.push_back(level);
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