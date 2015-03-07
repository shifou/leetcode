class Solution {
public:
vector<string> mlx(unordered_set<string> &dict,string & st)
{
    vector<string> aa;
    for(int i=0;i<st.size();i++)
    {
        string op=st;
        for(int j='a';j<='z';j++)
        {
            op[i]=j;
            if(dict.find(op)!=dict.end())
               aa.push_back(op);
        }
    }
    return aa;
}
    int ladderLength(string start, string end, unordered_set<string> &dict) {
            queue<ok> q;
            ok hold;
            unordered_set<string> ha;
            ha.insert(start);
            hold.s=start;
            hold.step=1;
            q.push(hold);
            while(!q.empty())
            {
                ok temp=q.front();
                q.pop();
                if(temp.s==end)
                  return temp.step;
                vector<string> tt=mlx(dict,temp.s);
                for(int i=0;i<tt.size();i++)
                {
                    if(ha.find(tt[i])==ha.end())
                    {
                    hold.s=tt[i];
                    hold.step=temp.step+1;
                    q.push(hold);
                    ha.insert(tt[i]);
                    }
                }
            }
            return 0;
    }
};