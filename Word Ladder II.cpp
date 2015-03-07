class Solution {
public:
vector<int > mlx(vector<int> &mp,  unordered_set<int> &vis)
{
    vector<int> res;
    for(int i=0;i<mp.size();i++)
    {
        if(vis.find(mp[i])==vis.end())
        res.push_back(mp[i]);
    }
    
    return res;
}
void tryy(unordered_map<int, vector<int>> &res,unordered_map<int,string> &dict,unordered_map<string,int> &dict2,int id)
{
    for(int i=0;i<id;i++)
    {
        int sz = dict[i].size();
        string s =  dict[i];
        for (int k=0;k<sz;k++){
            s = dict[i];
            for (char j = 'a'; j<='z'; j++){
                s[k]=j;
                if (s!=dict[i]&&dict2.find(s)!=dict2.end()){
                     res[i].push_back(dict2[s]);
                }
            }
        }
    }
}
vector<string> converse(unordered_map<int,string> &i2d, vector<int> &in)
{
    vector<string> res;
    for(int i=0;i<in.size();i++)
    {
        res.push_back(i2d[in[i]]);
    }
    return res;
}
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
         queue<ok> q;
            ok hold;
            int id=0;
            unordered_map<int,string> i2d;
            unordered_map<string,int> d2i;
            int en;
            int st;
                unordered_set<int> used;
            for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();it++)
            {
                i2d[id]=*it;
                if(*it==end) en=id;
                if(*it==start) st=id;
                d2i[*it]=id++;
            }
           unordered_map <int, vector<int>> road;
            for(int i=0;i<id;i++)
            {
                vector<int> hh;
                road[i]=hh;
            }
            tryy(road,i2d,d2i,id);
            hold.pos=st;
            hold.step=1;
            used.insert(st);
            hold.path.push_back(st);
            q.push(hold);
            vector<vector<string> > na;
            int res=0;
            while(!q.empty())
            {
                vector<ok> mid;
                ok temp;
                while(!q.empty())
                {
                    temp=q.front();
                    mid.push_back(temp);
                    q.pop();
                }
                int flag=0;
                for(int i=0;i<mid.size();i++)
                {
                    temp=mid[i];
                    if(temp.pos==en)
                    {
                    
                         na.push_back(converse(i2d,temp.path)); 
                        flag=1;
                        continue;
                    }
                    else
                      used.insert(temp.pos);

                }
                if(flag || mid.size()==0)
                   return na;
                for(int i=0;i<mid.size();i++)
                {
                    temp=mid[i];
                vector<int> tt=mlx(road[temp.pos],used);
               
                for(int i=0;i<tt.size();i++)
                {
                    hold.pos=tt[i];
                    hold.step=temp.step+1;
                    hold.path=temp.path;
                    hold.path.push_back(tt[i]);
                   q.push(hold);
                }
            }
            }
           
     }
    
};