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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* h=NULL;
        ListNode* t=NULL;
        ListNode* temp=head;
        int i=1;
        while (temp!=NULL && i<=n){
            if(i==m-1)
                h=temp;
            if(i==n)
                t=temp;
            i++;
            temp=temp->next;
        }
        if(h!=NULL) {
            ListNode *t1 = h;
            h = h->next;
            temp = h;
            t1->next = NULL;


            ListNode *t2 = t->next;
            t->next = NULL;

            h = reverse(h);
            t1->next = h;
            temp->next = t2;
            return head;
        }

        ListNode *t2 = t->next;
        t->next = NULL;
        temp = head;
        h=reverse(head);
        temp->next=t2;
        return h;

    }
};