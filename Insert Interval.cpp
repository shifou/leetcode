class Solution {
public:
    vector<Interval> insert(vector<Interval> &a, Interval b) {
        vector<Interval> ans;
        if(a.size()==0)
        {
            ans.push_back(b);
            return ans;
        }
        int i=0;
      //  3 4 1 2 
      for(;i<a.size() && a[i].end < b.start;i++)
      {
             ans.push_back(a[i]);
       }
      if(i==a.size())
      {
          ans.push_back(b);
          return ans;
      }
      // 
      //  3 4 1 2
      //2 3  3 5
      // 2 4 3 5
      // 2 4  3 4
      // 
      for(;i<a.size() && b.end>=a[i].start;i++)
      {
          b.start=min(b.start,a[i].start);
          b.end=max(b.end,a[i].end);
      }
      ans.push_back(b);
      for(;i<a.size();i++)
         ans.push_back(a[i]);
    return ans;
    }
};