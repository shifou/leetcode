class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> q;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
              q.push(i);
             else
             {
                 if(!q.empty() && s[q.top()]=='(' )
                 {
                    q.pop();
                    if(q.empty())
                      ans=i+1;
                      else
                        ans=max(ans,i-q.top());
                 }
                 else
                   q.push(i);
             }
        }
        return ans;
    }
};