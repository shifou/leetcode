class Solution {
public:
    bool fk(int p1,int p2,string &s, string &t)
    {
        // ccccc
        // c*b*
       // printf("now: %d %d %c %c\n",p1,p2,s[p1],t[p2]);
        if(p1==s.size()&&p2==t.size())
           return true;
        else if(p1!=s.size()&&p2!=t.size())
        {
            if(t[p2+1]!='*')
            {
                if(t[p2]=='.'||t[p2]==s[p1])
                  return fk(p1+1,p2+1,s,t);
                else
                  return false;
            }
            else
            {
        // aaabaaaababcbccbaab
        // c*.*c*a*..*c*
                if(p2+2<=t.size())
                {
                //	printf("skip\n");
                	if( fk(p1,p2+2,s,t))
                    return true;
                }
                //	printf("no skip try %d %d %c %c\n",p1,p2,s[p1],t[p2]);
                for(int i=0;i<s.size() && p1+i+1 <=s.size()&&p2+2<=t.size() && (t[p2]=='.'||s[p1+i]==s[p1]);i++)
                {
                    if((t[p2]=='.'|| s[p1+i]==t[p2]) && fk(p1+i+1,p2+2,s,t))
                      return true;
                   
                }
                      return false;
            }
        }
         else if(p1==s.size()&&p2!=t.size())
        {
            while(p2!=t.size() && t[p2+1]=='*')
              p2+=2;
            if(p2==t.size())
               return true;
            else
              return false;
        }
        else
          return false;
    }
    bool isMatch(string s, string p) {
        int len1 = s.size();
        int len2=p.size();
        string ss=s,tt=p;
        if(tt==".*")
           return true;
        if(ss==""&&len2==2 && tt[1]=='*')
           return true;
        int h1=0,h2=0,pre=-1,press;
    
        int ct=0,ct1=0,ct2=0;
        for(int i=0;i<len2;i++)
        {
            if(tt[i]!='.'&&tt[i]!='*') ct++;
            if(tt[i]=='.') ct1++;
            if(tt[i]=='*') ct2++;
        }
        if(ct2==0 && ct1+ct!=len1) return false;
        // aaabaaaababcbccbaab
        // c*.*c*a*..*c*
        string hold="";
        for(int i=0;i<len2;)
        {
        	if(i+1<len2&&tt[i+1]=='*')
        	{
        		char pre=tt[i];
        		hold+=tt[i];
        		hold+='*';
        		i+=2;
        		for(;i+1<len2 &&tt[i]==pre &&tt[i+1]=='*';i+=2);
        	}
        	else
        	 {
        	 	hold+=tt[i];
        	 	i++;
        	 }
        }
        //puts(hold.c_str());
        return fk(0,0,ss,hold);
    }
};