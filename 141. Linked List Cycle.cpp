class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode* slow=head->next;
        ListNode* fast=slow->next;
        
        while (slow!=fast && fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast==NULL)
                break;
            fast=fast->next;
        }
        return slow==fast;
    }
};