class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL)
            return ans;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(to_string(root->val));
            return ans;
        }

        if(root->left!=NULL){
            vector<string> left=binaryTreePaths(root->left);
            for(int i=0;i<left.size();i++)
                ans.push_back(to_string(root->val)+"->"+left[i]);
        }
        if(root->right!=NULL){
            vector<string> right=binaryTreePaths(root->right);
            for(int i=0;i<right.size();i++)
                ans.push_back(to_string(root->val)+"->"+right[i]);
        }
        
        return ans;
    }
};