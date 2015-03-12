
class Solution {
public:
     
   int threeSumClosest(vector<int> &num, int target) {
       if(num.size()<=2)
          return 0;
        sort(num.begin(),num.end());
        int n=num.size()-1;
        int ans=0;
        int val=INT_MAX;
         for(int i=0;i<=n-2;i++)
         {
             int l=i+1;
             int r=n;
             while(l<r)
             {
                 int hold = num[l]+num[r]+num[i];
                 if(abs(hold-target)<val)
                 {
                     val=abs(hold-target);
                     ans = hold;
                 }
                 if(hold==target)
                 {
                     return ans;
                 }
                 else if(hold>target)
                      r--;
                else
                   l++;
             }
         }
         return ans;
    }       
};