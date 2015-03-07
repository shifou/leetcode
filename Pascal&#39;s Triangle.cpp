class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ans(numRows);
        if(numRows>=1)
            ans[0].push_back(1);
        if(numRows>=2)
        {
            ans[1].push_back(1);
            ans[1].push_back(1);
        }
        for(int i =2;i<numRows;i++)
        {
            ans[i].push_back(1);
            for(int j=1;j<i;j++)
            {
                ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};