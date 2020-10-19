class Pair{
public:
    TreeNode* node;
    unsigned long long int d;
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        Pair p;
        p.node=root;
        p.d=1;
        queue<Pair> pending;
        pending.push(p);
        Pair flag;
        flag.node=NULL;
        flag.d=0;
        pending.push(flag);
        unsigned long long int minW=0;
        unsigned long long int maxW=0;
        int ans=INT_MIN;
        while (pending.size()!=0){
            Pair temp=pending.front();
            pending.pop();
            if(temp.node==NULL){
                if(pending.size()!=0)
                    pending.push(flag);
                int d=maxW-minW+1;
                ans=max(ans,d);
                maxW=0;
                minW=0;
                continue;
            }
            if(temp.d<minW || minW==0)
                minW=temp.d;
            if(temp.d>maxW || maxW==0)
                maxW=temp.d;
            if(temp.node->left!=NULL){
                p.node=temp.node->left;
                p.d=2*temp.d;
                pending.push(p);
            }
            if(temp.node->right!=NULL){
                p.node=temp.node->right;
                p.d=2*temp.d+1;
                pending.push(p);
            }
        }
        return ans;
    }
};