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
class Pair{
public:
    TreeNode* node;
    int state;
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<Pair> rec;
        Pair temp;
        temp.node=root;
        temp.state=1;
        rec.push(temp);
        
        while(rec.size()!=0){
            temp=rec.top();
            rec.pop();
            if(temp.state==3)
                continue;
            if(temp.state==2)
                ans.push_back(temp.node->val);
            Pair t=temp;
            t.state++;
            rec.push(t);
            if(temp.state==1 && temp.node->left!=NULL){
                t.node=temp.node->left;
                t.state=1;
                rec.push(t);
            }
            if(temp.state==2 && temp.node->right!=NULL){
                t.node=temp.node->right;
                t.state=1;
                rec.push(t);
            }
        }
        return ans;
    }
};