class Solution {
public:

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int len=S.size();
        vector<ok > ans;
        vector<int> a;
        for(int i=0;i<(1<<len);i++)
        {
            a.clear();
        for(int j=0;j<len;j++)
        {
            if(i&(1<<j))
            a.push_back(S[j]);
            
        }
        sort(a.begin(),a.end());
        ok hold;
        hold.ans=a;
        ans.push_back(hold);
        }
        a.clear();
        sort(ans.begin(),ans.end());
       vector<ok>::iterator new_end=unique(ans.begin(),ans.end());
        ans.erase(new_end,ans.end());
        vector<vector<int> > res;
        //res.push_back(a);
        for(int i=0;i<ans.size();i++) 
        {
            //if(ans[i].ans.size()>0)
            res.push_back(ans[i].ans);
        }
        return res;
    }
};