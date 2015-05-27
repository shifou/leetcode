class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> q;
        for(int i=0;i<nums.size();i++)
            q.insert(nums[i]);
        return (nums.size())?nums.size()!=q.size():false;
    }
};