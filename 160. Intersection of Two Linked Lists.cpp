class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int len1=0,len2=0;
        ListNode* temp1=head1;
        ListNode* temp2=head2;
        while (temp1!=NULL){
            len1++;
            temp1=temp1->next;
        }
        while (temp2!=NULL){
            len2++;
            temp2=temp2->next;
        }
        
        if(len1>len2){
            for(int i=0;i<(len1-len2);i++)
                head1=head1->next;
        }
        if(len2>len1){
            for(int i=0;i<(len2-len1);i++)
                head2=head2->next;
        }
        
        while (head1!=head2){
            head1=head1->next;
            head2=head2->next;
        }
        
        return head1;
    }
};