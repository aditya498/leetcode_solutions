class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index;
        index.push(-1);
        int len=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                index.push(i);
            else{
                if(index.top()!=-1 && s[index.top()]=='(')
                    index.pop();
                else
                    index.push(i);
                len=max(len,i-index.top());
            }
        }
        return len;
    }
};