class Solution {
public:
    string minWindow(string S, string T) {
        int len=0;
        int a[256];
        int ct[256]; 
        memset(a,0,sizeof(a));
        
        memset(ct,0,sizeof(ct));
        for(int i=0;i<T.size();i++)
           a[T[i]]++;
        int st=0,res=0,ans=S.size();
        for(int i=0;i<S.size();i++)
        {
            if(a[S[i]])
                ct[S[i]]++;
            else
              continue;
            //cabwefgewcwaefgcf
            //0123456789
            //cae
            //cabwefg
            //       ewcwaefgc
            if(ct[S[i]]<=a[S[i]])
              len++;
             if(len==T.size())
             {
                while(st<=i-T.size()+1)
                {
                    if(!a[S[st]])
                        st++;
                    else if(ct[S[st]]>a[S[st]])
                    {
                        ct[S[st]]--;
                        st++;
                    }
                    else
                      break;
                }
                if(i-st+1<ans)
                {
                    res=st;
                  ans=i-st+1;
                }
                if(ans==T.size())
                  break;
             }
        }
        if(len==T.size())
           return S.substr(res,ans);
        else
        return "";
    }
};