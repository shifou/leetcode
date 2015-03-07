class Solution {
public:
    int minDistance(string word1, string word2) {
        int h1 = word1.size();
        int h2 = word2.size();
        if(h1==0)
           return h2;
          if(h2==0)
            return h1;
        if(h1<h2) {swap(word1,word2),swap(h1,h2);}
        int ans[h2+1];
        for(int i=0;i<=h2;i++)
          ans[i]=i;
        for(int i=0;i<h1;i++)
        {
            int newans[h2+1];
            newans[0]=i+1;
            for(int j=0;j<h2;j++)
            {
                if(word1[i]==word2[j])
                   newans[j+1]=ans[j];
                 else
                 {
                     newans[j+1]=min(newans[j],min(ans[j],ans[j+1]))+1;
                 }
            }
           // for(int i=0;i<=h2;i++)
            //  printf("%d ",ans[i]);
           //   puts("");
           //              for(int i=0;i<=h2;i++)
          //    printf("%d ",newans[i]);
          //    puts("");
            memcpy(ans,newans,sizeof(int)*(h2+1));
            //            for(int i=0;i<=h2;i++)
           //   printf("%d ",ans[i]);
          //    puts("");
           //
        }
        return ans[h2];
    }
};