class Solution {
public:
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
void mlx(vector<vector<char>> &grid,int x,int y)
{
    grid[x][y]='0';
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&grid[xx][yy]=='1')
            mlx(grid,xx,yy);
    }
}
    int numIslands(vector<vector<char>> &grid) {
        n=grid.size();
        if(n)
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    mlx(grid,i,j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};