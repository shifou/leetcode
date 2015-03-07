class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
           return false;
        int a[12]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000};
        //x=abs(x);
        int len=0;
        for(int j=x;j>0;j/=10) len++;
        for(int i=0;i<len/2;i++) 
            {
                if(x%10!=x/a[len-2*i-1])
               return false;
               x=x%a[len-2*i-1]/10;
            }
        //1001
        return true;
    }
};