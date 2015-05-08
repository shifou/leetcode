class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        while(n!=1 && hash.find(n)==hash.end())
        {
            hash.insert(n);
            int sum=0;
            while(n)
            {
                sum+=((n%10)*(n%10));
                n/=10;
            }
            n=sum;
        }
        if(n==1)
            return true;
        else
            return false;
    }
};