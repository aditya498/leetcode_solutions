class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg=0,tc=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            tg+=gas[i];
            tc+=cost[i];
        }

//        if total gas required is greater than total gas available then return -1
        if(tc>tg)
            return -1;

        int available=0;
        int i=0,j=0;
        while (j<n){
            if(available+gas[j]<cost[j]){
                available=0;
                i=j+1;
            } else
                available=available+gas[j]-cost[j];
            j++;
        }
        return i;
    }
};