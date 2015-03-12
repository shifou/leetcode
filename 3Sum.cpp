class Solution {
public:
     //a b c d e f
     // -a=b+c
     //a<b<c
     // b+f=-a
     // = -c
     // a<b  -a>-b
     // -4 -1 -1 0 1 2 
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if(num.size()<=2)
          return ans;
        sort(num.begin(),num.end());
        vector<int> hold;
        int n=num.size()-1;
         for(int i=0;i<=n-2;i++)
         {
             if(num[i]>0)
                break;
            if(i&&num[i]==num[i-1]) 
               continue;
               hold.clear();
                hold.push_back(num[i]);
             int tg = -num[i];
             int l=i+1;
             int r=n;
             while(l<r)
             {
                 if(num[l]+num[r]==tg)
                 {
                     hold.push_back(num[l]);
                     hold.push_back(num[r]);
                     ans.push_back(hold);
                     l++,r--;
                     while(l<r&&num[l-1]==num[l]) l++;
                     while(r>l&&num[r+1]==num[r]) r--;
                     hold.pop_back();
                     hold.pop_back();
                     continue;
                 }
                 else if(num[l]+num[r]>tg)
                      r--;
                else
                   l++;
             }
         }
         return ans;
    }       
};