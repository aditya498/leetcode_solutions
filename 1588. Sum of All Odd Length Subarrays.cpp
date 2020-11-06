class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        for(int l=1;l<=arr.size();l+=2){
            int sum=0;
            for(int i=0;i<l;i++)
                sum+=arr[i];
            ans+=sum;
            for(int i=l;i<arr.size();i++){
                sum-=arr[i-l];
                sum+=arr[i];
                ans+=sum;
            }
        }
        return ans;
    }
};