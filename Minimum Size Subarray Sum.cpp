class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ans=nums.size()+1;
        int st=0,en=1,local=nums[0];
        if(local>=s)
            ans=1;
        while(en<nums.size())
        {
            while(local<s&&en<nums.size())
            {
                local+=nums[en++];
            }
            while(local>=s&&st<en)
            {
                ans=min(ans,en-st);
                local-=nums[st++];
            }
            if(ans==1)
                return ans;
        }
        if(ans==nums.size()+1)
            return 0;
        else
            return ans;
    }
};