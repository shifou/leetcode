class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(prices.size()<=1)
            return 0;
        int mina = 0x3fffffff;
        int maxa = 0;
        for(int i=0;i<prices.size();i++)
        {
            mina=min(mina, prices[i]);
            maxa = max(maxa,prices[i]-mina);
        }
        return maxa;
    }
};