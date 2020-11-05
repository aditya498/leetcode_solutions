class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* fh=NULL;
        ListNode* ft=NULL;

        ListNode* temp=NULL;
        while (head!=NULL){
            temp=head;
            while (temp!=NULL && head->val==temp->val)
                temp=temp->next;
            if(temp==head->next){
                if(fh==NULL){
                    fh=head;
                    ft=head;
                } else{
                    ft->next=head;
                    ft=head;
                }
            }
            head=temp;
        }
        if(ft!=NULL)
            ft->next=NULL;
        return fh;
    }
};