class Solution {
public:
    int trap(int A[], int n) {
        if(n<=2)
          return 0;
       int l=0,r=n-1;
       while(l+1<n&& A[l]<=A[l+1]) l++;
       if(l==n-1)
            return 0;
       while(r-1>=0&&A[r]<=A[r-1]) r--;
       if(r==0)
            return 0;
       int res=0;
       while(l<r)
       {
           if(A[l]<=A[r])
           {
               int lh = A[l++];
               while(l<r&&A[l]<lh)
               {
                   res+=(lh-A[l++]);
               }
           }
           else
           {
               int rh =A[r--];
               while(l<r&&A[r]<rh)
               {
                   res+=(rh-A[r--]);
               }
               
           }
       }
       return res;
    }
};