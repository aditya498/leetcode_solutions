class MyStack {
private:
    queue<int> rec1;
    queue<int> rec2;
public:

    MyStack() {
    }

    void push(int x) {
        if(rec1.size()!=0)
            rec1.push(x);
        else
            rec2.push(x);
    }

    int pop() {
        if(rec1.size()!=0){
            while (rec1.size()!=1){
                rec2.push(rec1.front());
                rec1.pop();
            }
            int ans=rec1.front();
            rec1.pop();
            return ans;
        } else{
            while (rec2.size()!=1){
                rec1.push(rec2.front());
                rec2.pop();
            }
            int ans=rec2.front();
            rec2.pop();
            return ans;
        }
    }

    int top() {
        if(rec1.size()!=0){
            while (rec1.size()!=1){
                rec2.push(rec1.front());
                rec1.pop();
            }
            int ans=rec1.front();
            rec2.push(ans);
            rec1.pop();
            return ans;
        } else{
            while (rec2.size()!=1){
                rec1.push(rec2.front());
                rec2.pop();
            }
            int ans=rec2.front();
            rec1.push(ans);
            rec2.pop();
            return ans;
        }
    }

    bool empty() {
        return rec1.empty() && rec2.empty();
    }
};