class Solution {
public:
void mlx(vector<vector<string> > &ans,vector<string> hold, int row,int ld,int rd)
{
    if(row==mask)
    {
        ans.push_back(hold);
        return;
    }
    int pos = mask & (~(row| ld| rd));
    while(pos)
    {
        int h=pos& -pos;
        pos-=h;
        int c =0, d=0,m=row ;
        for (c =0; m; m >>=1) 
            c += m &1 ;
        for(d=0,m=h;(1<<d)!=h;d++);
        hold[c][len-1-d]='Q';
        mlx(ans,hold,row+h,(ld+h)<<1,(rd+h)>>1);
        hold[c][len-1-d]='.';
    }
}
    vector<vector<string> > solveNQueens(int n) {
        len=n;
        mask=(1<<n)-1;
        vector<vector<string> > ans;
        vector<string> hold;
        string s="";
        for(int j=0;j<n;j++) s+='.';
        for(int i=0;i<n;i++) hold.push_back(s);
        mlx(ans,hold,0,0,0);
        return ans;
    }
};