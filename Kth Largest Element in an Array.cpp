class Solution {
public:
    void quick(vector<int> &nums,int l,int r,int k)
    {
        int pivot = nums[r];
        int i=l,j=r;
        while(i<j)
        {
            while(i<j&&nums[i]<=pivot) i++;
            while(j>i&&nums[j]>=pivot) j--;
            if(i<j)
            {
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i],nums[r]);
        if(i==k)
           return;
        else if(i>k)
            quick(nums,l,i-1,k);
        else
            quick(nums,i+1,r,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        quick(nums,0,n-1,n-k);
        return nums[n-k];
    }
};