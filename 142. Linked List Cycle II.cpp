class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head->next;

        while (fast!=NULL && slow!=fast){
            slow=slow->next;
            fast=fast->next;
            if(fast==NULL)
                break;
            fast=fast->next;
        }
        if(fast==NULL)
            return NULL;
        fast=head;
        while (slow->next!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};