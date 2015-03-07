class Solution {
public:
    double pow(double x, int n) {
        if(n==0)
          return 1;
        if(n==1) return x;
        else if(n==2)
            return x*x;
        else{
            int flag=0;
            if(n<0)
            {
                flag=1;
                n=-n;
            }
            double hold=pow(x,n/2);
            double temp;
            if(n&1)
               temp= x*hold*hold;
            else
                temp= hold*hold;
            if(flag)
                temp=1/temp;
            return temp;
        }
    }
};