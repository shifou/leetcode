class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n);
        for(int i=0;i<n;i++) 
        ans[i].resize(n);
        int h=1,p1=0,p2=0,l1=n-1,l2=n-1;
        while(h<=n*n)
        {
            for(int i=p2;i<=l2;i++) ans[p1][i]=h++;
            if(++p1>l1) break;
            for(int i=p1;i<=l1;i++) ans[i][l2]=h++;
            if(--l2<p2) break;
            for(int i=l2;i>=p2;i--) ans[l1][i]=h++;
            if(--l1<p1) break;
            for(int i=l1;i>=p1;i--) ans[i][p2]=h++;
            if(++p2>l2) break;
        }
        return ans;
    }
};