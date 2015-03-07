class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int end = m+n-1;
        int h1=m-1;
        int h2=n-1;
        while(h1>=0||h2>=0)
        {
            if(h1==-1)
            {
                if(h2>=0)
                    memcpy(A,B,sizeof(int)*(h2+1));
                break;
            }
            if(h2==-1)
                break;
            if(A[h1]>B[h2])
                A[end]=A[h1--];
            else
                A[end]=B[h2--];
            end--;
        }
    }
};