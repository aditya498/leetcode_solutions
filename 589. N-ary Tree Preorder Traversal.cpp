class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        ans.push_back(root->val);
        for(int i=0;i<root->children.size();i++){
            vector<int> temp=preorder(root->children[i]);
            for(int j=0;j<temp.size();j++)
                ans.push_back(temp[j]);
        }
        return ans;
    }
};