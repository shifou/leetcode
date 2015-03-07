class Solution {
public:
    int climbStairs(int n) {
        int x=1,y=2;
        if(n==1) return 1;
        if(n==2) return 2;
        else
        {
            int hold;
            for(int i=1;i<=n-2;i++)
            {
                hold=x+y;
                x=y;
                y=hold;
            }
            return hold;
        }
    }
};