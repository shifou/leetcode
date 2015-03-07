class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> q;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int h1=q.top();
                q.pop();
                int h2=q.top();
                q.pop();
                if(tokens[i]=="+")
                  h2+=h1;
                 else if(tokens[i]=="-")
                 h2-=h1;
                 else if(tokens[i]=="*")
                 h2*=h1;
                 else
                   h2/=h1;
                 q.push(h2);
            }
            else
            {
                int hh=0,j=0;
                if(tokens[i][0]=='-')
                 j=1;
                for(;j<tokens[i].size();j++) hh=hh*10+tokens[i][j]-'0';
                if(tokens[i][0]=='-') hh=-hh;
                q.push(hh);
            }
        }
        return q.top();
    }
};