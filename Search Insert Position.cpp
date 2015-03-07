class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(A[0]>target)
            return 0;
        for(int i=0;i<n;i++)
        {
            if(A[i]==target)
                return i;
            if(A[i]>target)
                return i;
            else
                continue;
        }
        return n;
        
    }
};