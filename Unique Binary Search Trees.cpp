class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
          vector<int> A(n+1,0);
          A[0]=1;
          A[1]=1;
          A[2]=2;

        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                A[i]+=A[j]*A[i-j-1];
            }
        }
        return A[n];
        
        
    }
};