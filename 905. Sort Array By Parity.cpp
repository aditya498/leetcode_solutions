class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        while (l<r){
            if(arr[l]%2!=0 && arr[r]%2==0){
                swap(arr[l],arr[r]);
                l++;
                r--;
            } else if(arr[l]%2==0 && arr[r]%2!=0){
                l++;
                r--;
            } else if(arr[l]%2==0)
                l++;
            else
                r--;
        }
        return arr;
    }
};