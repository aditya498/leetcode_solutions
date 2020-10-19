void merge(vector<int> &nums,vector<int> &index,int s,int m,int e,vector<int> &ans){
    int l=s,r=m+1;
    vector<int> aux;
    while (l<=m && r<=e){
        if(nums[index[l]]<=nums[index[r]])
            aux.push_back(index[l++]);
        else{
            for(int i=l;i<=m;i++)
                ans[index[i]]++;
            aux.push_back(index[r++]);
        }
    }

    while (l<=m)
        aux.push_back(index[l++]);
    while (r<=e)
        aux.push_back(index[r++]);

    for(int i=s;i<=e;i++)
        index[i]=aux[i-s];
}

void mergeSort(vector<int> &nums,vector<int> &index,int l,int r,vector<int> &ans){
    if(l>=r)
        return;
    int m=(l+r)/2;
    mergeSort(nums,index,l,m,ans);
    mergeSort(nums,index,m+1,r,ans);
    merge(nums,index,l,m,r,ans);
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> index(nums.size());
        for(int i=0;i<nums.size();i++)
            index[i]=i;
        mergeSort(nums,index,0,nums.size()-1,ans);
        return ans;
    }
};