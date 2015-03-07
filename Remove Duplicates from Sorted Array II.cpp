class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2)
            return n;
        int p=2;
        // 1 1 1 1 1 
        // 1 1 2 
        // 1 2 3
        // 1 2 2
        for(int i=2;i<n;i++)
        {
            if(A[i]!=A[p-1]||A[i]!=A[p-2])
                A[p++]=A[i];
        }
        return p;
    }
};