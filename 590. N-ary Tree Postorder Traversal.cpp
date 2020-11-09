class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        for(int i=0;i<root->children.size();i++){
            vector<int> temp=postorder(root->children[i]);
            for(int j=0;j<temp.size();j++)
                ans.push_back(temp[j]);
        }
        ans.push_back(root->val);
        return ans;
    }
};