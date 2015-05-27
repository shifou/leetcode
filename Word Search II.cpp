struct ok
{
    int end;
    int next[26];
};
ok a[50005];
int id=1;
bool vis[101][101];
class Solution {
public:
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
    void check(int x,int y,int cur,vector<string> & ans,string hold,vector<vector<char>>& board)
    {
        vis[x][y]=1;
        hold+=board[x][y];
        if(a[cur].end)
        {
            ans.push_back(hold);
            a[cur].end=0;
        }
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&xx<board.size()&&yy>=0&&yy<board[0].size()&&!vis[xx][yy] && a[cur].next[board[xx][yy]-'a'])
            {
                check(xx,yy,a[cur].next[board[xx][yy]-'a'],ans,hold,board);
            }
        }
        vis[x][y]=0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        vector<string> ans;
        if(id!=1)
        {
            for(int i=0;i<=id;i++)
            {
                a[i].end=0;
                memset(a[i].next,0,sizeof(a[i].next));
            }
            id=1;
        }
        memset(vis,0,sizeof(vis));
        int used[26]={0};
        for(int i=0;i<words.size();i++)
        {
            int cur=1;
            used[words[i][0]-'a']+=1;
            for(int j=0;j<words[i].size();j++)
            {
                if(!a[cur].next[words[i][j]-'a'])
                {
                    a[cur].next[words[i][j]-'a']=++id;
                }
                cur= a[cur].next[words[i][j]-'a'];
            }
            a[cur].end=1;
        }
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(used[board[i][j]-'a'])
                {
                    int pre = ans.size();
                    check(i,j,a[1].next[board[i][j]-'a'],ans,"",board);
                    if(ans.size()>pre)
                        used[board[i][j]-'a']-=1;
                }
            }
        }
        return ans;
    }
};