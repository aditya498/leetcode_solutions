class Pair{
public:
    int minV;
    int maxV;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        
        int minE=INT_MAX,maxE=INT_MIN;
        for(int i=0;i<nums.size();i++){
            minE=min(minE,nums[i]);
            maxE=max(maxE,nums[i]);
        }
        
        int avg=ceil((maxE-minE)/float(nums.size()-1));
        
        vector<Pair> buckets(nums.size()-1);
        for(int i=0;i<nums.size()-1;i++){
            buckets[i].minV=INT_MAX;
            buckets[i].maxV=INT_MIN;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minE || nums[i]==maxE)
                continue;
            int b=(nums[i]-minE)/avg;
            buckets[b].minV=min(buckets[b].minV,nums[i]);
            buckets[b].maxV=max(buckets[b].maxV,nums[i]);
        }
        
        int prev = minE;
        int maxGap = 0;
        for(int i=0;i<buckets.size();i++){
            if(buckets[i].maxV==INT_MIN)
                continue;
            maxGap = max(buckets[i].minV-prev,maxGap);
            prev = buckets[i].maxV;
        }
        maxGap = max(maxE-prev,maxGap);

        return maxGap;
    }
};