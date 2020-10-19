class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int* arr=new int[nums.size()];
        stack<int> rec;
        for(int i=nums.size()-1;i>=0;i--){
            while (rec.size()!=0 && nums[rec.top()]<=nums[i])
                rec.pop();
            if(rec.size()==0)
                arr[i]=i;
            else
                arr[i]=rec.top();
            rec.push(i);
        }

        vector<int> ans;
        int j=0;
        for(int i=0;(i+k)<=nums.size();i++){
            if(j<i)
                j=i;
            int e=i+k-1;
            while(true){
                if(arr[j]==j || arr[j]>e)
                    break;
                j=arr[j];
            }
            ans.push_back(nums[j]);
        }
        
        delete[] arr;
        return ans;
    }
};