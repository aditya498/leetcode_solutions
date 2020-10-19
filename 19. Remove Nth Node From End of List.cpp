class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* h=head;
        ListNode* prev=NULL;
        for(int i=0;i<n;i++)
            temp=temp->next;
        while (temp!=NULL){
            prev=h;
            h=h->next;
            temp=temp->next;
        }
        
        if(prev==NULL){
            ListNode* t=head->next;
            delete head;
            return t;
        }
        
        prev->next=h->next;
        delete h;
        return head;
    }
};