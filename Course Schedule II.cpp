
struct edge
{
    int to,next;
};
edge e[2000005];
int head[50000];
class Solution {
public:
int id;
void addedge(int par,int child)
{
    e[id].to=child;
    e[id].next=head[par];
    head[par]=id++;
}
    vector<int> findOrder(int num, vector<pair<int, int>>& pre)
    {
        vector<int> ans;
        vector<int> empty;
        id=0;
        vector<int> in(num,0);
        memset(head,-1,sizeof(head));
        for(int i=0;i<pre.size();i++)
        {
            int x = pre[i].first,y=pre[i].second;
            addedge(y,x);
            in[x]++;
        }
        int n=num;
        while(n--)
        {
            int pos=-1;
            for(int i=0;i<num;i++)
            {
                if(in[i]==0){pos=i;in[i]=-1;break;}
            }
            if(pos==-1)
                return empty;
            else
                ans.push_back(pos);
            for(int i=head[pos];i!=-1;i=e[i].next){
                    in[e[i].to]--;
                }
            
        }
        return ans;
    }
};