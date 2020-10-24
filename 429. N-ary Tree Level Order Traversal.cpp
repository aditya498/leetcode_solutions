class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        queue<Node*> pending;
        pending.push(root);
        vector<int> level;
        pending.push(NULL);
        
        while (pending.size()!=0){
            Node* temp=pending.front();
            pending.pop();
            
            if(temp==NULL){
                ans.push_back(level);
                level.clear();
                if(pending.size()!=0)
                    pending.push(NULL);
                continue;
            }
            
            level.push_back(temp->val);
            
            for(int i=0;i<temp->children.size();i++)
                pending.push(temp->children.at(i));
        }
        
        return ans;
    }
};