class Pair{
public:
    bool val;
    int split;
};

class Solution {
public:
    bool wordBreak(string str, vector<string>& wordDict) {
        Pair** dp=new Pair*[str.size()];
        for(int i=0;i<str.size();i++)
            dp[i]=new Pair[str.size()];

        unordered_set<string> rec;
        for(int i=0;i<wordDict.size();i++)
            rec.insert(wordDict[i]);

        for(int l=1;l<=str.size();l++){
            for(int i=0;i<str.size();i++){
                int s=i;
                int e=i+l-1;
                if(e>=str.size())
                    break;
                dp[s][e].val=false;
                dp[s][e].split=-1;
                if(rec.find(str.substr(s,l))!=rec.end()) {
                    dp[s][e].val=true;
                    dp[s][e].split=-1;
                    continue;
                }

                for(int j=s;j<e;j++){
                    dp[s][e].val=dp[s][j].val && dp[j+1][e].val;
                    dp[s][e].split=j;
                    if(dp[s][e].val)
                        break;
                }
            }
        }

        bool ans=dp[0][str.size()-1].val;

        for(int i=0;i<str.size();i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};