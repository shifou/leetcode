class Solution {
public:
  void dfs(vector<vector<char>> &board, int x, int y,char c)
  {
      board[x][y]=c;
      if(x+1<board.size() && board[x+1][y]=='O') dfs(board,x+1,y,c);
      if(x-1>=0 && board[x-1][y]=='O') dfs(board,x-1,y,c);
      if(y+1<board[0].size() && board[x][y+1]=='O') dfs(board,x,y+1,c);
      if(y-1>=0 && board[x][y-1]=='O') dfs(board,x,y-1,c);
  }
    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;
        for(int i=0;i<board[0].size();i++) if(board[0][i]=='O') dfs(board,0,i,'D');
        for(int i=0;i<board[0].size();i++) if(board[board.size()-1][i]=='O') dfs(board,board.size()-1,i,'D');
        for(int i=0;i<board.size();i++) if(board[i][0]=='O') dfs(board,i,0,'D');
        for(int i=0;i<board.size();i++) if(board[i][board[0].size()-1]=='O') dfs(board,i,board[0].size()-1,'D');
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++) 
            {
                if(board[i][j]=='O') dfs(board,i,j,'X');
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++) 
            {
                if(board[i][j]=='D') board[i][j]='O';
            }
        }
    }
};