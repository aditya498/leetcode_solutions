class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        pair<int,int>** dp=new pair<int,int>*[nums.size()];
        for(int i=0;i<nums.size();i++){
            dp[i]=new pair<int,int>[nums.size()];
        }

        for(int n=0;n<nums.size();n++) {
            for (int i = 0; i < nums.size(); i++) {
                int s = i, e = s + n;
                if (e >= nums.size())
                    break;
                if(s==e){
                    dp[s][e].first=nums[s];
                    dp[s][e].second=0;
                    continue;
                }
                int op1 = nums[s] + dp[s + 1][e].second;
                int op2 = nums[e] + dp[s][e - 1].second;
                if (op1 > op2) {
                    dp[s][e].first = op1;
                    dp[s][e].second = dp[s + 1][e].first;
                } else if (op1 < op2) {
                    dp[s][e].first = op2;
                    dp[s][e].second = dp[s][e - 1].first;
                } else {
                    if (dp[s + 1][e].first < dp[s][e - 1].first) {
                        dp[s][e].first = op1;
                        dp[s][e].second = dp[s + 1][e].first;
                    } else {
                        dp[s][e].first = op2;
                        dp[s][e].second = dp[s][e - 1].first;
                    }
                }
            }
        }

        bool ans=dp[0][nums.size()-1].first>=dp[0][nums.size()-1].second;

        for(int i=0;i<nums.size();i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};