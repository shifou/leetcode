class Solution {
public:
int m,n;
vector<ok> p;
cell cc[9];
bool flag;
inline bool check(ok &p,int& val,vector<vector<char> > &board)
{
    int x=p.x,y=p.y;
    
    for (int i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)  
            for (int j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)  
                if (i != x && j != y && board[i][j] == val+'0')  
                    return false;  
        return true;  
}
bool mlx(int pos, vector<vector<char> > &board)
{
    if(pos==p.size())
       return true;
        ok hold = p[pos];
        int tt = p[pos].x/3*3+p[pos].y/3;
        for(int j=1;j<=9;j++)
        {
            if(row[hold.x][j]==0&&col[hold.y][j]==0&&cc[tt].num[j]==0)
            {
                row[hold.x][j]=col[hold.y][j]=1;
                board[hold.x][hold.y]='0'+j;
                cc[tt].num[j]=1;
                if(mlx(pos+1,board))
                   return true;
                row[hold.x][j]=col[hold.y][j]=0;
                board[hold.x][hold.y]='.';
                cc[tt].num[j]=0;
               
            }
        }
    return false;
}
    void solveSudoku(vector<vector<char> > &board) {
         if(board.size() != 9 || board[0].size() !=9)  
        return;  
        flag=false;
        p.clear();
        for(int i=0;i<9;i++)
        {
            cc[i].ct=0;
            memset(cc[i].num,0,sizeof(cc[i].num));
        }
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        n=board.size();
        m=board[0].size();
             for(int i=0;i<n;i++)
            {
            for(int j=0;j<m;j++)
            {
                int hold = i/3*3+j/3;
                if(board[i][j]=='.')
                {
                    ok a;
                    a.x=i;
                    a.y=j;
                    p.push_back(a);
                }
                else
                {
                    
                    cc[hold].ct++;
                    cc[hold].num[board[i][j]-'0']=1;
                row[i][board[i][j]-'0']=1;
                col[j][board[i][j]-'0']=1;
                }
            }
        }
        mlx(0,board);
    }
};