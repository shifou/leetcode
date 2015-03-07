class Solution {
public:
    void dfs(vector<vector<int> > & ans,vector<int> hold,vector<int> &a,int pos, int val,int fin)
    {
        //cout<<"-----"<<pos<<"\t"<<val<<"\t"<<fin<<endl;
        if(val==fin)
        {
           ans.push_back(hold);
           return;
        }
        for(int i=pos;i<a.size();i++)
        {
            if(val+a[i]<=fin)
            {
                hold.push_back(a[i]);
                dfs(ans,hold,a,i,val+a[i],fin);
                hold.pop_back();
            }
            else if(val+a[i]>fin)
              return;
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > ans;
        vector<int> hold;
        dfs(ans,hold,candidates,0,0,target);
        return ans;
    }
    
};