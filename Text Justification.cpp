class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        //if(L==0&& words[])
        for(int i=0;i<words.size();)
        {
            int cur=words[i].size();
            string st=words[i];
            int len=cur,ge=0,j=i+1;
            for(;j<words.size() && cur+1+words[j].size()<=L;j++)
            {
                cur+=(1+words[j].size());
                len+=words[j].size();
                ge++;
            }
            if(ge==0)
            {
                st.append(L-cur,' ');
                ans.push_back(st);
                i++;
                continue;
            }
            if(j==words.size())
            {
                 for(int hh=i+1;hh<j;hh++)
               {
                 st.append(1,' ');
                
                st.append(words[hh]);
               }
               st.append(L-cur,' ');
               ans.push_back(st);
               return ans;
            }
            int avg = (L-len)/ge;
            //a b c d e
            int ex = (L-len)%ge;
            for(int hh=i+1;hh<j;hh++)
            {
                st.append(avg,' ');
                if(ex)
                {
                    st.append(1,' ');
                    ex--;
                }
                st.append(words[hh]);
            }
            ans.push_back(st);
            i=j;
        }
        return ans;
    }
};