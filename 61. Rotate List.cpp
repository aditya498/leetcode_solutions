class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int len=0;
        ListNode* temp=head;
        while (temp!=NULL){
            temp=temp->next;
            len++;
        }

        k=k%len;
        if(k==0)
            return head;
        int i=0;
        temp=head;
        ListNode* t=NULL;
        while (i<=k){
            t=temp;
            temp=temp->next;
            i++;
        }
        
        ListNode* h=head;
        while (temp!=NULL){
            t=temp;
            temp=temp->next;
            h=h->next;
        }
        
        t->next=head;
        head=h->next;
        h->next=NULL;
        return head;
    }
};