class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
         int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
         int x=0,y=-1;
         vector<int> ans;
         int l[2]={matrix[0].size(),matrix.size()-1};
         int n=0,k=0;
         while(n<matrix.size()*matrix[0].size())
         {
             int dx=dir[k%4][0];
             int dy=dir[k%4][1];
             //cout<<"-----"<<l[k%2]<<endl;
             for(int j=0;j<l[k%2];j++,n++)
             {
                 x+=dx;
                 y+=dy;
                 ans.push_back(matrix[x][y]);
                // cout<<x<<"\t"<<y<<"\t"<<matrix[x][y]<<endl;
             }
             l[k%2]--;
             k++;
         }
         return ans;
    }
};