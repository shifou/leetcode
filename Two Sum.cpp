class Solution {
public:

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<ok> q;
        for(int i=0;i<(int)numbers.size();i++)
        {
            ok a;
            a.val=numbers[i];
            a.index=i+1;
            q.push_back(a);
        }
        vector<int > res;
        sort(q.begin(),q.end(),cmp);
        int h1=0,h2=q.size()-1;
        int t1,t2;
        while(h1!=h2)
        {
            if(q[h1].val+q[h2].val==target)
            {
                res.push_back(q[h1].index);
                res.push_back(q[h2].index);
               break;
            }
            else if(q[h1].val+q[h2].val<target) h1++;
            else h2--;
        }
        sort(res.begin(),res.end());
        return res;
    }
};