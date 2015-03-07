class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int len=S.size();
        vector<vector<int> > ans;
        vector<int> a;
        for(int i=1;i<(1<<len);i++)
        {
            a.clear();
        for(int j=0;j<len;j++)
        {
            if(i&(1<<j))
            a.push_back(S[j]);
            
        }
        sort(a.begin(),a.end());
        ans.push_back(a);
        }
        a.clear();
        ans.push_back(a);
        return ans;
    }
};