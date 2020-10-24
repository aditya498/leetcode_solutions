class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        for(int i=0;i<root->children.size();i++)
            ans=max(ans,maxDepth(root->children.at(i)));
        return 1+ans;
    }
};