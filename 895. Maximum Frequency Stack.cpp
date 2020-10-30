class FreqStack {
private:
    unordered_map<int,stack<int>> rec;
    unordered_map<int,int> freq;
    int maxFreq;
public:
    FreqStack() {
        maxFreq=0;
    }

    void push(int x) {
        freq[x]+=1;
        rec[freq[x]].push(x);
        maxFreq=max(maxFreq,freq[x]);
    }

    int pop() {
        int ans=rec[maxFreq].top();
        rec[maxFreq].pop();
        freq[ans]--;
        if(rec[maxFreq].empty())
            maxFreq--;
        return ans;
    }
};