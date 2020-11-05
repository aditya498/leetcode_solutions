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
    int getDecimalValue(ListNode* head) {
        head=reverse(head);
        int f=1;
        int ans=0;
        while (head!=NULL){
            ans=ans+head->val*f;
            f*=2;
            head=head->next;
        }
        return ans;
    }
};