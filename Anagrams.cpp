class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        string hold;
        map<string,vector<int> >aa;
        for(int i=0;i<strs.size();i++)
        {
            hold=strs[i];
            sort(hold.begin(),hold.end());
            aa[hold].push_back(i);
        }
        for(auto it=aa.begin();it!=aa.end();it++)
        {
            vector<int> qq=it->second;
            if(qq.size()>1)
            {
                for(int i=0;i<qq.size();i++)
                {
                    ans.push_back(strs[qq[i]]);
                }
               // break;
            }
        }
        return ans;
    }
};