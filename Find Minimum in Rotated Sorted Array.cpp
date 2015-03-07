class Solution {
public:
//2 1
//0 1
    int findMin(vector<int> &num) {
        int l=0,r=num.size()-1;
        while(l<r)
        {
            if(num[l]<num[r])  return num[l];
            int mid = (l+r)/2;
            if(num[mid]<num[r])
               r=mid;
             else
               l=mid+1;
        }
        return num[l];
    }
};