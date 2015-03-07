class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> hold;
        if(s=="") return 0;
        int ans=0,st=0,t=0;
        for(int i=0;i<s.size();i++)
        {
            if(hold.find(s[i])!=hold.end())  st=max(st,hold[s[i]]+1);
          
                ans=max(ans,i-st+1);
               
                hold[s[i]]=i;
           
        }
        return ans;
    }
};