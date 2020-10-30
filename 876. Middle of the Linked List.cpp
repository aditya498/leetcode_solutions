class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while (fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            if(fast==NULL)
                break;
            fast=fast->next;
        }
        return slow;
    }
};