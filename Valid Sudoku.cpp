class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i=0;i<board.size();i++)
        {
            int flag[10]={0};
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                    flag[board[i][j]-48]++;
            }
            for(int j=0;j<10;j++)
                if(flag[j]>1)
                    return false;
        }
        for(int i=0;i<board[0].size();i++)
        {
            int flag[10]={0};
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i]!='.')
                    flag[board[j][i]-48]++;
            }
            for(int j=0;j<10;j++)
                if(flag[j]>1)
                    return false;
        }
        for(int i=0;i<board.size();i+=3)
        {
           
            for(int k=0;k<board[0].size();k+=3)
            {
                 int flag[10]={0};
                for(int j=i;j<i+3;j++)
                {
                    for(int p=k;p<k+3;p++)
                        if(board[j][p]!='.')
                            flag[board[j][p]-48]++;
                }
             for(int j=0;j<10;j++)
                if(flag[j]>1)
                    return false;
            }
        }
        return true;
    }
};