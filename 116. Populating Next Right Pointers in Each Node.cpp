class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;

        queue<Node*> pending;
        pending.push(root);
        Node* flag=NULL;
        pending.push(flag);
        Node* prev=NULL;
        while (pending.size()!=0){
            Node* temp=pending.front();
            pending.pop();
            if(temp==NULL){
                if(pending.size()!=0)
                    pending.push(flag);
                prev->next=NULL;
                prev=NULL;
                continue;
            }
            if(prev==NULL)
                prev=temp;
            else {
                prev->next = temp;
                prev = temp;
            }
            if(temp->left!=NULL)
                pending.push(temp->left);
            if(temp->right!=NULL)
                pending.push(temp->right);
        }
        return root;
    }
};