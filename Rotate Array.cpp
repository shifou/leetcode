class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k%=n;

        int st=n-k;
        reverse(nums,nums+st);
        reverse(nums+st,nums+n);
        reverse(nums,nums+n);
    }
};