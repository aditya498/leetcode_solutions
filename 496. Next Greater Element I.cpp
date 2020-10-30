class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> index;
        for(int i=0;i<nums1.size();i++)
            index[nums1[i]]=-1;
        for(int i=0;i<nums2.size();i++){
            if(index.find(nums2[i])!=index.end())
                index[nums2[i]]=i;
        }

        vector<int> temp(nums2.size());
        stack<int> rec;
        for(int i=nums2.size()-1;i>=0;i--){
            while (rec.size()!=0 && nums2[i]>rec.top())
                rec.pop();
            if(rec.size()==0)
                temp[i]=-1;
            else
                temp[i]=rec.top();
            rec.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
            ans.push_back(temp[index[nums1[i]]]);
        return ans;
    }
};