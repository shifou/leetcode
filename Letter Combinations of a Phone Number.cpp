class Solution {
public:
void dfs(vector<string> &ans,string & s,int pos, string hold,map<int,string> &mp)
{
    if(pos==s.size())
    {
        ans.push_back(hold);
        return;
    }
    for(int i=0;i<mp[s[pos]-'0'].size();i++)
    {
        dfs(ans,s,pos+1,hold+mp[s[pos]-'0'][i],mp);
    }
}
    vector<string> letterCombinations(string digits) {
        map<int, string> keypad;
        keypad[2] = string("abc");
        keypad[3] = string("def");
        keypad[4] = string("ghi");
        keypad[5] = string("jkl");
        keypad[6] = string("mno");
        keypad[7] = string("pqrs");
        keypad[8] = string("tuv");
        keypad[9] = string("wxyz");
        vector<string> ans;
        dfs(ans,digits,0,"",keypad);
        return ans;
    }
};