vector<int> twoSum(vector<int> &numbers, int target){
        vector<int> ans;
        int left = 1, right = numbers.size();
        long long tmpSum = 0;

        while(left < right){
            tmpSum = (long long)numbers[left - 1] + (long long)numbers[right - 1];
            if (tmpSum == target){
                ans.push_back(left);
                ans.push_back(right);
                return ans;
            }else if (tmpSum > target){
                right--;
            }else{
                left++;
            }
        }
        return ans;
    }