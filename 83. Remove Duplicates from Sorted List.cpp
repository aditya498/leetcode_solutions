ListNode* helper(ListNode* head,ListNode* prev){
    if(head==NULL)
        return head;
    if(prev!=NULL && head->val==prev->val){
        ListNode* temp=head->next;
        delete head;
        return helper(temp,prev);
    } else
        head->next=helper(head->next,head);
    return head;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return helper(head,NULL);
    }
};