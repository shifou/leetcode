class Solution {
public:
    int majorityElement(vector<int> &num) {
        int res;int ct=0;
        for(int i=0;i<num.size();i++)
        {
            if(ct==0)
            {
                res=num[i];
                ct=1;
            }
            else if(res==num[i])
              ct++;
              else 
              {
                  ct--;
              }
        }
        return res;
    }
};