class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans =0;
        int flag=0;
        if(x<0)
        {
            x=-x;
            flag=1;
        }
        while(x)
        {
            ans = ans *10 + x%10;
            x/=10;
        }
        if(flag)
            ans = -ans;
        return ans;
    }
};