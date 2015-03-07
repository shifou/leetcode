class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int len1=strlen(s);
        int len2=strlen(p);
        int ct=0;
        int ct1=0,ct2=0;
        for(int i=0;i<len2;i++)
        {
            if(p[i]!='*'&&p[i]!='?') ct++;
            if(p[i]=='?') ct1++;
            if(p[i]=='*') ct2++;
        }
        if(ct>len1) return false;
        if(ct2==0&& (ct+ct1!=len1))  return false;
         string ss=s;
        string tt=p;
        if(tt=="*")  return true;

        int h1=0,h2=0,pre=-1,press;
        for(;h1<len1 ;)
        {
        	//printf("ss[%d] %c tt[%d] %c\n",h1,ss[h1],h2,tt[h2]);
            if(tt[h2]=='?'||ss[h1]==tt[h2]) {h1++,h2++;continue;}
            if(h1==5&&h2==3) printf("wtf\n");
            if(tt[h2]=='*')
            {
                while(h2<len2&& tt[h2]=='*') h2++;
                pre=h2-1;
                press=h1;
                // printf("find %d %d go %d %d\n",press,pre,h1,h2);
                //printf("ss[%d] %c???\n",press,ss[press]);
                continue;
            }
            // abc
            // a*
            if(pre!=-1)
            {
                h1=++press;
                h2=pre;
               // printf("next %d %d\n",h1,h2);
                continue;
            }
            return false;
        }
        //printf("-----%d %d %d %d\n",h1,h2,pre,press);
         while(h2<len2&& tt[h2]=='*') h2++;
         if(h2==len2 && h1==len1)
            return true;
    else
      return false;
    }
};