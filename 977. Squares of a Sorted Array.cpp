class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
            arr[i]=abs(arr[i]);
        
        int l=0,r=arr.size()-1;
        
        vector<int> res(arr.size());
        int n=arr.size()-1;
        while (l<=r){
            if(arr[l]>arr[r]){
                res[n]=arr[l]*arr[l];
                l++;
            } else{
                res[n]=arr[r]*arr[r];
                r--;
            }
            n--;
        }

        return res;
    }
};