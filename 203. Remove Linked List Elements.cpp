class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        if(head->val==val){
            ListNode* temp=head->next;
            delete head;
            return removeElements(temp,val);
        }
        head->next=removeElements(head->next,val);
        return head;
    }
};