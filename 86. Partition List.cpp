class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1=NULL;
        ListNode* tail1=NULL;
        ListNode* head2=NULL;
        ListNode* tail2=NULL;
        
        while (head!=NULL){
            if(head->val<x){
                if(head1==NULL){
                    head1=head;
                    tail1=head;
                } else{
                    tail1->next=head;
                    tail1=head;
                }
            } else{
                if(head2==NULL){
                    head2=head;
                    tail2=head2;
                } else{
                    tail2->next=head;
                    tail2=head;
                }
            }
            head=head->next;
        }
        
        if(head1==NULL)
            return head2;
        if(head2==NULL)
            return head1;
        tail1->next=head2;
        tail2->next=NULL;
        return head1;
    }
};