int l[34001];
int r[34001];
class Solution {
public:
    int maxProfit(vector<int> &price) {
        if(price.size()==0)
          return 0;
        int n = price.size();
        memset(l,0,sizeof(int)*n);
        memset(r,0,sizeof(int)*n);
        int mm=price[0];
        for(int i=1;i<n;i++)
        {
            l[i]=max(l[i-1],price[i]-mm);
            mm=min(price[i],mm);
        }
        mm=price[n-1];
        int ans=l[n-1];
        for(int i=n-2;i>=0;i--)
        {
            r[i]=max(r[i+1],mm-price[i]);
            mm=max(price[i],mm);
             ans=max(ans,l[i]+r[i]);
        }
        return ans;
    }
};