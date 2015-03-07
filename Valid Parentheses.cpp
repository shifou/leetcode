class Solution {
public:
    bool isValid(string s) {
        if(s.size()&1)
         return false;
        if(s=="[]" || s=="()" || s=="{}" || s=="")
          return true;
if(s[0]=='['||s[0]=='{'||s[0]=='(')
{
            int pos= ff(s[0],s);;
            if(pos==-1)
             return false;
             else
               return isValid(s.substr(1,pos-1)) && isValid(s.substr(pos+1));
        }
       
        else 
            return false;
    }
    int ff(char c, string &s)
    {
        if(c=='[')
        {
            int sum=0;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]==c)
                  sum++;
                 if(s[i]==']')
                 {
                     if(sum==0)
                        return i;
                     else
                       sum--;
                 }
            }
        }
        else
        if(c=='(')
        {
            int sum=0;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]==c)
                  sum++;
                 if(s[i]==')')
                 {
                     if(sum==0)
                        return i;
                     else
                       sum--;
                 }
            }
        }
        else if(c=='{')
        {
            int sum=0;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]==c)
                  sum++;
                 if(s[i]=='}')
                 {
                     if(sum==0)
                        return i;
                     else
                       sum--;
                 }
            }
        }
    }
};