class Solution {
public:
    string getPermutation(int n, int k) {
       vector<bool> a(11,0);
       k-=1;
       string s="";
       for(int i=n-1;i>=0;i--)
       {
           int h1=k/fac[i];
           int h2=k%fac[i];
           int ct=0;
           for(int j=1;j<=n;j++)
            {
                if(!a[j]) ct+=1;
                if(ct==h1+1)
                {
                   a[j]=1;
                   s+=('0'+j);
                   break;
                }
            }
            k=h2;
       }
       return s;
    }
};