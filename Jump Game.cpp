class Solution {
public:
    bool canJump(int A[], int n) {
        int ans=0,st=0,en=0;
        while(st<=en)
        {
            en=max(en,st+A[st]);
            st++;
            if(en>=n-1) return true;
        }
        return false;
    }
};