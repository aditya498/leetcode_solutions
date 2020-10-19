class Codec {
public:

    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        vector<string> temp;
        queue<TreeNode*> pending;
        pending.push(root);
        while (pending.size()!=0){
            TreeNode* cur=pending.front();
            pending.pop();
            if(cur==NULL){
                temp.push_back("null");
                continue;
            }
            temp.push_back(to_string(cur->val));
            pending.push(cur->left);
            pending.push(cur->right);
        }

        while (temp.size()!=0){
            if(temp[temp.size()-1]=="null")
                temp.pop_back();
            else
                break;
        }

        string ans="";
        for(int i=0;i<temp.size();i++){
            ans=ans+temp[i]+" ";
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        vector<string> rec;
        string t="";
        for(int i=0;i<data.size();i++){
            if(data[i]==' '){
                rec.push_back(t);
                t="";
                continue;
            }
            t+=data[i];
        }
        if(t!="")
            rec.push_back(t);
        int i=0;
        if(rec[0]=="null")
            return NULL;
        TreeNode* root=new TreeNode(stoi(rec[i++]));
        queue<TreeNode*>pending;
        pending.push(root);

        while(i<rec.size()){
            TreeNode* temp=pending.front();
            pending.pop();
            if(rec[i]=="null")
                temp->left=NULL;
            else {
                TreeNode* t=new TreeNode(stoi(rec[i]));
                temp->left=t;
                pending.push(temp->left);
            }
            i++;
            if(i>=rec.size())
                break;
            if(rec[i]=="null")
                temp->right=NULL;
            else {
                TreeNode* t=new TreeNode(stoi(rec[i]));
                temp->right=t;
                pending.push(temp->right);
            }
            i++;
        }
        return root;
    }
};
