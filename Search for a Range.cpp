class Solution {
public:
int fk1(int A[],int n,int mu)
{
    int mid,s=0,t=n-1;
    while(s<=t)
    {
        mid=(s+t)>>1;
        if(A[mid]<mu)
            s=mid+1;
        else
            t=mid-1;
    }
    return s;
}
int fk2(int A[],int n,int mu)
{
    int mid,s=0,t=n-1;
    while(s<=t)
    {
        mid=(s+t)>>1;
        if(A[mid]<=mu)
            s=mid+1;
        else
            t=mid-1;
    }
    return t;
}
    vector<int> searchRange(int A[], int n, int target) {
        int h1=fk1(A,n,target);
        int h2= fk2(A,n,target);
        vector<int> ans(2,-1);
        if(h1<=h2)
        {
            ans[0]=h1;
            ans[1]=h2;
        }
        
        return ans;
    }
    
};