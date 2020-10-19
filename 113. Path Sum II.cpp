vector<vector<int>> helper(TreeNode* root,int sum){
    if(root->left==NULL && root->right==NULL){
        sum=sum-root->val;
        vector<vector<int>> ans;
        if(sum==0){
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        return ans;
    }

    vector<vector<int>>ans;
    if(root->left!=NULL){
        vector<vector<int>>left=helper(root->left,sum-root->val);
        for(int i=0;i<left.size();i++){
            vector<int> temp;
            temp.push_back(root->val);
            for(int j=0;j<left[i].size();j++)
                temp.push_back(left[i][j]);
            ans.push_back(temp);
        }
    }

    if(root->right!=NULL){
        vector<vector<int>>right=helper(root->right,sum-root->val);
        for(int i=0;i<right.size();i++){
            vector<int> temp;
            temp.push_back(root->val);
            for(int j=0;j<right[i].size();j++)
                temp.push_back(right[i][j]);
            ans.push_back(temp);
        }
    }

    return ans;
}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;

        return helper(root,sum);
    }
};