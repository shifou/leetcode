class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int len=triangle.size();
        int a[triangle[len-1].size()];
        for(int i=0;i<triangle[len-1].size();i++) a[i]=triangle[len-1][i];
        for(int i=len-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                a[j]=triangle[i][j]+min(a[j],a[j+1]);
            }
        }
        return a[0];
    }
};