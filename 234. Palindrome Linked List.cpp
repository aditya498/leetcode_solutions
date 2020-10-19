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
    bool isPalindrome(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while (temp!=NULL){
            len++;
            temp=temp->next;
        }
        
        if(len==1 || len==0)
            return true;
        
        len=len/2+len%2;
        
        temp=head;
        for(int i=0;i<len;i++)
            temp=temp->next;
        ListNode* head2=temp;
        head2=reverse(head2);
        ListNode* head1=head;
        while (head2!=NULL){
            if(head1->val!=head2->val)
                return false;
            head1=head1->next;
            head2=head2->next;
        }
        
        return true;
    }
};