class Solution {
public:
    bool isNumber(string s) {
        int st=0;
        while(s[st]==' ' && st<s.size()) st++;
        if(st==s.size())
           return false;
                   s=s.substr(st);
        int en=s.size()-1;
        while(en>=0 && s[en]==' ') en--;

        for(int i=0;i<en;i++)
        {
            if(isdigit(s[i]) || s[i]=='e' ||s[i]=='.' || s[i]=='-' ||s[i]=='+')
              continue;
            else
              return false;
        }
        int be=0;
                int e=0,p=0,num=0;
        if(s[0]=='-'|| s[0]=='+')
        {
            be++;
        }
        if(s[be]=='.')
        {
            p=1;
            be++;
        }
        if(isdigit(s[be])==false)
          return false;
if(be==en)
   return true;
        for(int i=be;i<=en;i++)
        {
            if(isdigit(s[i]))
            {
              continue;
            }
            else if(s[i]=='e')
            {
                if(e==1 ) return false;
                else
                {
                   if(s[i-1]!='.'&&isdigit(s[i-1])==false)
                     return false;
                   e=1;
                }
            }
            else if(s[i]=='.')
            {
                if(p ||e) return false;
                else
                {
                   
                  p=1;
                }
            }
            else if(s[i]=='-' ||s[i]=='+')
            {
                if(e &&num==0)
                {
                    num=1;
                  continue;
                }
                  else
                  return false;
            }
            else
              return false;
        }
        if(isdigit(s[en]) || s[en]=='.')
        return true;
        else
          return false;
    }
};