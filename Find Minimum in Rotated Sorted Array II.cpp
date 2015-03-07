class Solution {
public:
    int findMin(vector<int> &num) {
        int l=0,r=num.size()-1;
        while(l<r)
        {
            if(num[l]<num[r])  return num[l];
            //while()
            int mid = (l+r)/2;
            if(num[mid]<num[r])
               r=mid;
             else if(num[mid]==num[r])
                l++;
             else
               l=mid+1;
        }
        return num[l];
    }
};