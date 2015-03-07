class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int index=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            A[index++]=A[i];
            int j;
            for(j=i+1;j<n;j++)
            {
                if(A[j]!=A[i])
                    break;
                else
                    count++;
            }
            i=j-1;
        }
        return n-count;
        
    }
};