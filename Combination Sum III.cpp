class Solution {
public:
int vis[10];
    void mlx(vector<vector<int>> & ans, int k, int n, int sum, int num, vector<int> hold,int pos )
    {
        if(num==k)
        {
            if(sum==n)
                ans.push_back(hold);
            return;
        }
        for(int i=pos;i<=9;i++)
        {
            if(!vis[i]&&sum+i<=n&&num+1<=k)
            {
                vis[i]=1;
                hold.push_back(i);
                mlx(ans,k,n,sum+i,num+1,hold,i+1);
                hold.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        memset(vis,0,sizeof(vis));
        vector<vector<int>> ans;
        vector<int> hold;
        mlx(ans,k,n,0,0, hold,1);
        return ans;
    }
};