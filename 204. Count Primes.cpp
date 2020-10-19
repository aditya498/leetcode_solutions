class Solution {
public:
    int countPrimes(int n) {
        bool* freq=new bool[n+1]{0};
        for(int i=2;i<=n;i++){
            if(freq[i])
                continue;
            for(int j=2;j<=n/i;j++)
                freq[i*j]=true;
        }
        
        int ans=0;
        for(int i=2;i<n;i++){
            if(!freq[i])
                ans++;
        }
        
        return ans;
    }
};