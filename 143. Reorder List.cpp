ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* h=reverse(head->next);
    ListNode* t=head->next;
    t->next=head;
    head->next=NULL;
    return h;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        ListNode* slow=head;
        ListNode* fast=head->next;
        ListNode* prev=NULL;
        while (fast!=NULL){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
            if(fast==NULL)
                break;
            fast=fast->next;
        }

        prev->next=NULL;
        ListNode* h2=reverse(slow);
        
        ListNode* fh=NULL;
        ListNode* ft=NULL;
        while (head!=NULL && h2!=NULL){
            if(fh==NULL){
                fh=head;
                ft=head;
            } else{
                ft->next=head;
                ft=head;
            }
            head=head->next;
            
            ft->next=h2;
            ft=h2;
            h2=h2->next;
        }
        
        if(h2!=NULL)
            ft->next=h2;
    }
};