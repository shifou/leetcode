class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<2)
            return 0;
        int mmax = *max_element(num.begin(), num.end());
        int mmin = *min_element(num.begin(),num.end());
        // 2 3 5
        int gap = (mmax-mmin)/num.size()+1;
        if(gap==0)
            return 0;
        int ans = gap;
        int bsize = (mmax-mmin)/gap+1;
        vector<int> buckMax(bsize,INT_MIN);
        vector<int> buckMin(bsize,INT_MAX);
        for(int i=0;i<num.size();i++)
        {
            // 12 23 34 1
            int id = (num[i]-mmin)/gap;
            if(num[i]>buckMax[id]) buckMax[id]=num[i];
            if(num[i]<buckMin[id]) buckMin[id]=num[i];
        }
        int pre = buckMax[0];
        for(int i=1;i<bsize;i++)
        {
            if(buckMin[i]==INT_MAX) continue;
            ans =max(ans,buckMin[i]-pre);
            pre = buckMax[i];
        }
        
        return ans;
        
    }
};