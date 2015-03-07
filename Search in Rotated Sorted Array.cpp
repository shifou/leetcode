class Solution {
public:
    int search(int A[], int n, int target) {
        int i=0, j=n-1;
        while(i<=j)
        {
            int mid = (i+j)>>1;
            if(A[mid]==target)
                return mid;
            if(A[i]<=A[mid])
            {
                if(target>=A[i] && target <A[mid])
                 j=mid-1;
                else
                    i=mid+1;
            }
            else
            {
                if(target > A[mid] && target <=A[j])
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        return -1;
    }
};