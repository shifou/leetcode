class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int pos=matrix.size()-1;
        if(target<matrix[0][0])
            return false;
        for(int i=0;i<matrix.size()-1;i++)
        {
            if(target>=matrix[i][0]&&target<matrix[i+1][0])
            {
                pos=i;
                break;
            }
        }
        for(int i=0;i<matrix[pos].size();i++)
        {
            if(matrix[pos][i]==target)
                return true;
        }
        return false;
    }
};