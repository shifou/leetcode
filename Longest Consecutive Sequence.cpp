class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> vis;
        for(int i=0;i<num.size();i++)
           vis.insert(num[i]);
        int ans=1;
        for(int i=0;i<num.size();i++)
        {
            if(vis.find(num[i])==vis.end()) continue;
            int hold = num[i]+1;
            int len=1;
            while(hold<(int)(num[i]+num.size()) && vis.find(hold)!=vis.end()) {vis.erase(hold);hold++,len++; }
            hold = num[i]-1;
            while(hold>(int)(num[i]-num.size()) && vis.find(hold)!=vis.end()) {vis.erase(hold);hold--,len++; }
            vis.erase(num[i]);
            if(len>ans)
               ans=len;
               
        }
        return ans;
    }
};