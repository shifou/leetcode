// 2 3 1 1 4
//     

class Solution {
public:
    int jump(int A[], int n) {
        if(n==0 || n==1)
           return 0;
        int step=0,ma=0,end=0;
       for(int i=0;i<n && ma<n-1;)
        {
            while(i<=end && ma<n-1)
            {
                ma=max(A[i]+i,ma);
                i++;
            }
            end = ma;
            step++;
        }
        return step;
    }
};