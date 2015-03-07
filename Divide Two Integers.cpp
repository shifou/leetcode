class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
          return 2147483647;
       long long a = dividend;
       long long b = divisor;
       unsigned int ans=0;
       int flag=0,flag2=0,fk=0;
       if(a<0)
         flag=1;
        if(b<0)
          flag2=1;
        fk=flag^flag2;

       if(b==0)
          return INT_MAX;
        if(b==1)
           return dividend;
         if(a==0)
            return 0;
                             a=a>0?a:-a;
        b=b>0?b:-b;
       if(a<b)
         return 0;
        else if(a==b)
           return fk?-1:1;
         else
         {

             long long hold=1;
             long  long d = b;
             while(d<a)
             {
                 hold<<=1;
                 d<<=1;
             }
             if(d>a)
             {
             d>>=1;
             hold>>=1;
             }
             while(hold>=1 && a)
             {
                 while(a>=d)
                 {
                  ans+=(int)hold;
                  a-=d;
                 }
                 d>>=1;
                hold>>=1;
             }
             if(fk)
                return -ans;
            else
            return ans;
         }
    }
};