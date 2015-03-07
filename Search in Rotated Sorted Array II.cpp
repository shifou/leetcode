class Solution {
public:
bool mlx(int A[], int st, int en, int res)
{
    int mid;
    while(st<en)
    {
        mid= (st+en)>>1;
        if(A[mid]<res) st=mid+1;
        else if(A[mid]==res) return true;
        else en=mid;
    }
    return false;
}
    bool search(int A[], int n, int target) {
        int pos=0;
        for(int i=1;i<n;i++)
        {
            if(A[i]<A[i-1]){pos=i; break;} 
        }
        return mlx(A,0,pos,target) | mlx(A, pos, n,target);
    }
};