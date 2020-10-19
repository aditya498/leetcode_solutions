class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* h=reverseList(head->next);
        ListNode* t=head->next;
        t->next=head;
        head->next=NULL;
        return h;
    }
};