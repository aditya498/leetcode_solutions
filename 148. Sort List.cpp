ListNode* getMid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;

    while (fast!=NULL){
        fast=fast->next;
        if(fast==NULL)
            break;
        slow=slow->next;
        fast=fast->next;
    }

    return slow;
}

ListNode* merge(ListNode* head1,ListNode* head2){
    ListNode* fh=NULL;
    ListNode* ft=NULL;
    ListNode* temp=NULL;
    while (head1!=NULL && head2!=NULL){
        if(head1->val<head2->val) {
            temp = head1;
            head1=head1->next;
        }else {
            temp = head2;
            head2=head2->next;
        }
        if(fh==NULL){
            fh=temp;
            ft=temp;
        } else{
            ft->next=temp;
            ft=temp;
        }
    }

    if(head1!=NULL)
        ft->next=head1;
    if(head2!=NULL)
        ft->next=head2;

    return fh;
}


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* mid=getMid(head);

        ListNode* head1=head;
        ListNode* head2=mid->next;
        mid->next=NULL;

        head1=sortList(head1);
        head2=sortList(head2);

        return merge(head1,head2);
    }
};