class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            
            int ct=0,bit=1<<i;
            for(int j=0;j<n;j++)
            {
                if(A[j]&bit)
                    ct++;
            }
            if(ct%3)
                ans|=bit;
        }
        return ans;
    }
};