int helper(int** dp,bool** isPalindrome,int s,int e){
    if(s>e)
        return 0;
    if(isPalindrome[s][e])
        return 0;
    if(dp[s][e]>-1)
        return dp[s][e];

    int ans=9999;
    for(int i=s;i<e;i++)
        ans=min(ans,helper(dp,isPalindrome,s,i)+helper(dp,isPalindrome,i+1,e));

    dp[s][e]=1+ans;
    return dp[s][e];
}

class Solution {
public:
    int minCut(string str) {
        int n=str.size();
        bool** isPalindrome=new bool*[n];
        for(int i=0;i<n;i++)
            isPalindrome[i]=new bool[n]{0};
        for(int l=1;l<=n;l++){
            for(int i=0;i<n;i++){
                int s=i,e=i+l-1;
                if(e>=n)
                    break;
                else if(s==e)
                    isPalindrome[s][e]=true;
                else if(s==e-1) {
                    if(str[s]==str[e])
                        isPalindrome[s][e]=true;
                }else{
                    if(str[s]==str[e])
                        isPalindrome[s][e]=isPalindrome[s+1][e-1];
                    else
                        isPalindrome[s][e]=false;
                }
            }
        }

//         to pass edge test case (required for some cases of leetcode)
        if(isPalindrome[0][n-1])
            return 0;
        for(int i=0;i<n-1;i++){
            if(isPalindrome[0][i] && isPalindrome[i+1][n-1])
                return 1;
        }

        int** dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }

        int ans=helper(dp,isPalindrome,0,n-1);

        for(int i=0;i<n;i++){
            delete[] dp[i];
            delete[] isPalindrome[i];
        }
        delete[] dp;
        delete[] isPalindrome;

        return ans;
    }
};