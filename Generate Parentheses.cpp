class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string > ans;
        if(n==0)
         return ans;
        else
            print(ans, n-1,n,"(");
        return ans;
        
    }
    void print(vector<string> & a, int be, int la, string hold)
    {
        if(be==0&& la==0)
        {
            a.push_back(hold);
            return;
        }
        if(be>0)
            print(a,be-1,la,hold+'(');
        if(la>0&& la>be)
            print(a,be,la-1,hold+')');
    }
};