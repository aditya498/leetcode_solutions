class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> rec;
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            int s=digits[i]+carry;
            carry=s/10;
            rec.push(s%10);
        }
        
        vector<int> ans;
        if(carry==1)
            ans.push_back(carry);
        while (rec.size()!=0){
            ans.push_back(rec.top());
            rec.pop();
        }
        return ans;
    }
};