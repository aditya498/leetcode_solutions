class compare{
public:
    bool operator()(ListNode* head1,ListNode* head2){
        return head1->val>head2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }

        ListNode* head=NULL;
        ListNode* tail=NULL;

        while (pq.size()!=0){
            ListNode* temp=pq.top();
            pq.pop();
            if(head==NULL){
                head=temp;
                tail=temp;
            } else{
                tail->next=temp;
                tail=temp;
            }
            temp=temp->next;
            if(temp!=NULL)
                pq.push(temp);
        }
        
        return head;
    }
};