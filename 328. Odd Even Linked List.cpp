class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* he=NULL;
        ListNode* ho=NULL;
        ListNode* te=NULL;
        ListNode* to=NULL;
        int num=1;
        while(head!=NULL){
            if(num%2==0){
                if(he==NULL){
                    he=head;
                    te=head;
                } else{
                    te->next=head;
                    te=head;
                }
            } else{
                if(ho==NULL){
                    ho=head;
                    to=head;
                } else{
                    to->next=head;
                    to=head;
                }
            }
            num++;
            head=head->next;
        }

        if(ho==NULL && he==NULL)
            return NULL;
        else if(ho==NULL) {
            te->next=NULL;
            return he;
        }
        else if(he==NULL) {
            to->next=NULL;
            return ho;
        }

        to->next=he;
        te->next=NULL;
        return ho;
    }
};