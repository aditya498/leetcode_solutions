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
    ListNode* swapPairs(ListNode* head){
        int k=2;
        ListNode* fhead=NULL;
        ListNode* ftail=NULL;
        while (head!=NULL){
            ListNode* h=head;
            int i=1;
            while (i<k && head!=NULL){
                i++;
                head=head->next;
            }
            if(head==NULL && i==k){
                ListNode* t=(h);
                if(fhead==NULL)
                    fhead=t;
                else
                    ftail->next=t;
            }else if(head==NULL && i!=k) {
                if(fhead==NULL)
                    fhead=h;
                else
                    ftail->next=h;
            }else{
                ListNode* temp=head->next;
                head->next=NULL;
                ListNode* t=reverse(h);
                if(fhead==NULL){
                    fhead=t;
                    ftail=h;
                } else{
                    ftail->next=t;
                    ftail=h;
                }
                head=temp;
            }
        }
        return fhead;
    }
};