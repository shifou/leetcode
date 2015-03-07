class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size()==1) return intervals; 
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> ans;
        if(intervals.size()==0) return ans; 
        int s=intervals[0].start,e=intervals[0].end;
        Interval hold;
        for(int i=1;i<=intervals.size();i++)
        {
            if(i==intervals.size())
            {
                hold.start=s;
                hold.end=e;
                ans.push_back(hold);
                break;
            }
            if(intervals[i].start<=e)
            {
                if(intervals[i].end>e)
                {
                    e=intervals[i].end;
                }
            }
            else
            {
                hold.start=s;
                hold.end=e;
                ans.push_back(hold);
                s=intervals[i].start;
                e=intervals[i].end;
                continue;
            }
        }
        return ans;
    }
};