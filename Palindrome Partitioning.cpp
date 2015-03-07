class Solution {
public:
     bool check(string s)
     {
         for(int i=0;i<s.size()/2;i++)
         {
             if(s[i]!=s[s.size()-1-i])
                return false;
         }
         return true;
     }
     void dfs(vector<vector<string> > &ans,vector<string> &hold,int pos,string &s)
     {
         if(pos==s.size())
         {
             ans.push_back(hold);
            return;
         }
        string fk="";
         for(int i=pos;i<s.size();i++)
         {
             fk+=s[i];
             if(check(fk))
             {
                 hold.push_back(fk);
                 dfs(ans,hold,i+1,s);
                 hold.pop_back();
             }
         }
     }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> hold;
        dfs(ans,hold,0,s);
        return ans;
    }
};