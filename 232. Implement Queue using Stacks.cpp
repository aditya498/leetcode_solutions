class MyQueue {
private:
    stack<int> rec1;
    stack<int> rec2;
public:

    MyQueue() {
    }

    void push(int x) {
        rec1.push(x);
    }

    int pop() {
        while (rec1.size()!=1){
            rec2.push(rec1.top());
            rec1.pop();
        }
        int ans=rec1.top();
        rec1.pop();
        while (rec2.size()!=0){
            rec1.push(rec2.top());
            rec2.pop();
        }
        return ans;

    }

    int peek() {
        while (rec1.size()!=1){
            rec2.push(rec1.top());
            rec1.pop();
        }
        int ans=rec1.top();
        rec2.push(ans);
        rec1.pop();
        while (rec2.size()!=0){
            rec1.push(rec2.top());
            rec2.pop();
        }
        return ans;

    }

    bool empty() {
        return rec1.empty() && rec2.empty();
    }
};
