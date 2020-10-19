class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        ListNode* temp=NULL;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<head2->val) {
                temp = head1;
                head1 = head1->next;
            } else{
                temp=head2;
                head2=head2->next;
            }
            if(head==NULL){
                head=temp;
                tail=temp;
            } else{
                tail->next=temp;
                tail=temp;
            }
        }
        if(head1!=NULL){
            if(head==NULL)
                head=head1;
            else
                tail->next=head1;
        }
        if(head2!=NULL){
            if(head==NULL)
                head=head2;
            else
                tail->next=head2;
        }
        return head;
    }
};