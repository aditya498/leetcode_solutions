class Node{
public:
    long int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class MinStack {
    Node* head;
    long int minElement;
public:

    MinStack() {
        head=NULL;
        minElement=0;
    }

    void push(int x) {
        Node* temp=new Node(x);
        if(head==NULL) {
            head = temp;
            minElement=head->data;
            return;
        }
        temp->next=head;
        head=temp;
        if(head->data<minElement){
            head->data=head->data+(head->data-minElement);
            minElement=x;
        }
    }

    void pop() {
        if(head==NULL)
            return;
        if(head->data<minElement)
            minElement=2*minElement-head->data;
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    int top() {
        if(head==NULL)
            return 0;
        if(head->data<minElement)
            return minElement;
        else
            return head->data;
    }

    int getMin() {
        return minElement;
    }
};