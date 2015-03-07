class Solution {
public:
    int maxProduct(int A[], int n) {
       int lmin,lmax,ans;
       lmin=lmax=ans=A[0];
       for(int i=1;i<n;i++)
       {
           int h1=lmax*A[i];
           int h2= lmin*A[i];
           lmax=max(A[i],max(h1,h2));
           lmin=min(A[i],min(h1,h2));
           ans=max(ans,lmax);
       }
       return ans;
    }
};