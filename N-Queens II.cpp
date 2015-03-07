class Solution {
public:
void mlx(int &ans, int row,int ld,int rd)
{
    if(row==mask) 
    {
        ans++;
        return;
    }
    int pos= mask&(~(row|ld|rd));
    while(pos)
    {
        int h= pos & -pos;
        pos-=h;
        mlx(ans, row+h,(ld+h)<<1, (rd+h)>>1);
    }
}
    int totalNQueens(int n) {
        mask=(1<<n)-1;
        int ans=0;
        mlx(ans,0,0,0);
        return ans;
    }
};