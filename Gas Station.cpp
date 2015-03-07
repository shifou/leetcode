class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        if(gas.size()==1)
        {
            if(gas[0]<cost[0]) return -1;
            else return 0;
        }
        for(int j=0;j<gas.size();j++)
        {
            int sum=0;
        for(int i=j;i<gas.size();)
        {
          sum+=(gas[i]-cost[i]);
          if(sum<0) break;
          i=(i+1)%gas.size();
          if(i==j) break;
        }
       // sum+=(gas[j])
         if(sum>=0)
           return j;
        }
        return -1;
    }
};