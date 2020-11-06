pair<ListNode*,ListNode*> findMid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    ListNode* prev=NULL;
    while (fast!=NULL){
        fast=fast->next;
        if(fast==NULL)
            break;
        prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
    
    pair<ListNode*,ListNode*> ans;
    ans.first=prev;
    ans.second=slow;
    return ans;
}

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            TreeNode* root=NULL;
            return root;
        }
        
        pair<ListNode*,ListNode*> mid=findMid(head);
        TreeNode* root=new TreeNode(mid.second->val);
        
        ListNode* h2=mid.second->next;
        mid.second->next=NULL;
        
        ListNode* h1=NULL;
        if(mid.first!=NULL){
            h1=head;
            mid.first->next=NULL;
        }
        
        root->left=sortedListToBST(h1);
        root->right=sortedListToBST(h2);
        
        return root;
    }
};