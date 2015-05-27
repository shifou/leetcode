class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ft,sec,cur,ans;
        if(nums.size()<=3)
            return max(nums[0], nums.size() == 1 ? 0 : nums.size() == 2 ? nums[1] : max(nums[1], nums[2]));
        ft=nums[0],sec=max(ft,nums[1]);
        for(int i=2;i<nums.size()-1;i++)
        {
            cur = max(ft+nums[i],sec);
            ft=sec;
            sec=cur;
        }
        ans = sec;
        ft=nums[1],sec=max(nums[2],ft);
        for(int i=3;i<nums.size();i++)
        {
            cur = max(ft+nums[i],sec);
            ft=sec;
            sec=cur;
        }
        return max(ans,sec);
    }
};