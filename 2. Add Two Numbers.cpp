class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        int carry=0;
        while(head1!=NULL && head2!=NULL){
            int s=head1->val+head2->val+carry;
            ListNode* temp=new ListNode(s%10);
            if(head==NULL){
                head=temp;
                tail=temp;
            } else{
                tail->next=temp;
                tail=temp;
            }
            carry=s/10;
            head1=head1->next;
            head2=head2->next;
        }
        
        while (head1!=NULL){
            int s=head1->val+carry;
            ListNode* temp=new ListNode(s%10);
            tail->next=temp;
            tail=temp;
            carry=s/10;
            head1=head1->next;
        }

        while (head2!=NULL){
            int s=head2->val+carry;
            ListNode* temp=new ListNode(s%10);
            tail->next=temp;
            tail=temp;
            carry=s/10;
            head2=head2->next;
        }

        while (carry!=0){
            ListNode* temp=new ListNode(carry%10);
            tail->next=temp;
            tail=temp;
            carry=carry/10;
        }
        
        return head;
    }
};