bool compare(int n1,int n2){
    string s1=to_string(n1)+to_string(n2);
    string s2=to_string(n2)+to_string(n1);
    int i=0;
    while (i<s1.size()){
        if(s1[i]>s2[i])
            return true;
        if(s1[i]<s2[i])
            return false;
        i++;
    }
    return false;
}


void merge(vector<int> &nums,int s,int m,int e){
    int i=s,j=m+1;
    vector<int> aux;
    
    while (i<=m && j<=e){
        if(compare(nums[i],nums[j]))
            aux.push_back(nums[i++]);
        else
            aux.push_back(nums[j++]);
    }
    
    while (i<=m)
        aux.push_back(nums[i++]);
    
    while (j<=e)
        aux.push_back(nums[j++]);
    
    i=s;
    for(;i<=e;i++)
        nums[i]=aux[i-s];
}

void mergeSort(vector<int> &nums,int s,int e){
    if(s>=e)
        return;
    int m=(s+e)/2;
    mergeSort(nums,s,m);
    mergeSort(nums,m+1,e);
    merge(nums,s,m,e);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        string ans="";
        int i=0;
        for(;i<nums.size()-1;i++){
            if(nums[i]!=0)
                break;
        }
        for(;i<nums.size();i++)
            ans+=to_string(nums[i]);
        return ans;
    }
};