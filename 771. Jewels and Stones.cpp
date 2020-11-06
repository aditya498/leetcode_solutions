class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for(int i=0;i<J.size();i++)
            jewels.insert(J[i]);
        
        int ans=0;
        for(int i=0;i<S.size();i++)
            ans+=(jewels.find(S[i])!=jewels.end()?1:0);
        return ans;
    }
};