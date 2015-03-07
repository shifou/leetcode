class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i=0;
        while(i<n)
        {
            if(A[i]>0&&A[i]<=n&&A[i]!=A[A[i]-1])
              swap(A[i],A[A[i]-1]);
              else
              i++;
        }
        i=0;
        while(i+1==A[i] && i<n) i++;
        return i+1;
    }
};