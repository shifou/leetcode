class Solution {
public:
   int gcd(int a, int b)
{
    while (b)
    {
        int t = a % b;
        a = b; 
        b = t;
    }
    return a;
}
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        long long n=numerator;
        long long dn=denominator;
        int flag1=0,flag2=0;
        if(n<0){
           n=abs(n); flag1=1;}
        if(dn<0){
           dn=abs(dn); flag2=1;}
        long long q=n/dn;
        int r=n%dn;
        if(flag1^flag2 &&n!=0)  ans="-";
        ans+=to_string(q);
        if(r!=0)
        {
            ans+=".";
            int len=0;
            int gc=gcd(r,dn);
            long long cur=r/gc;
            long long hold=dn=dn/gc;
            int ct2=0,ct5=0;
            while(hold!=0&&hold%2==0) {hold/=2;ct2++;}
            while(hold!=0&&hold%5==0) {hold/=5;ct5++;}
            len=max(ct2,ct5);
            for(int i=0;i!=len;i++)
            {
                int tmp=cur*10/dn;
                ans+=to_string(tmp);
                cur=cur*10%dn;
            }
            if(cur==0)
            {
                //ans+=")";
                return ans;
            }
            else
              ans+="(";
            long long left=cur;
            do
            {
               int tmp=cur*10/dn;
                ans+=to_string(tmp);
                cur=cur*10%dn;
            }while(left!=cur);
            
            ans+=")";
                return ans;
            
        }
        else
          return ans;
           
    }
};