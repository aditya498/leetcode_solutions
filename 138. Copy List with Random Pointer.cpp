class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* temp=head;
        while (temp!=NULL){
            Node* t=new Node(temp->val);
            t->next=temp->next;
            temp->next=t;
            temp=t->next;
        }

        Node* old_node=head;
        Node* new_node=head->next;

        while (new_node!=NULL){
            if(old_node->random!=NULL)
                new_node->random=old_node->random->next;
            if(new_node->next==NULL)
                break;
            old_node=old_node->next->next;
            new_node=new_node->next->next;
        }

        old_node=head;
        new_node=head->next;
        Node* fh=NULL;
        Node* ft=NULL;
        Node* tail=NULL;
        head=NULL;
        while (new_node!=NULL){
            if(head==NULL){
                head=old_node;
                tail=old_node;
            } else{
                tail->next=old_node;
                tail=old_node;
            }
            if(fh==NULL){
                fh=new_node;
                ft=new_node;
            } else{
                ft->next=new_node;
                ft=new_node;
            }
            if(new_node->next==NULL)
                break;
            old_node=old_node->next->next;
            new_node=new_node->next->next;
        }
        ft->next=NULL;
        tail->next=NULL;
        return fh;
    }
};