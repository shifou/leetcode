class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,0);
        ans[0]=ans[1]=1;
        for(int i=2;i<=rowIndex;i++)
        {
            int pre= 0;
            //for(int i=0;i<=4;i++)
             //   printf("%d\t",ans[i]);
           // puts("");
            if(i&1)
            {
               // printf("%d-----:  ok\n",i);
                for(int j=1;j<=i/2;j++)
                {
                    ans[j]=ans[j-1]+ans[j]-pre;
                    pre=ans[j-1]-pre;
                }
            }
            else
            {
                 //1 3
                for(int j=1;j<i/2;j++)
                {
                    ans[j]=ans[j-1]+ans[j]-pre;
                    pre=ans[j-1]-pre;
                }
                if(pre==0) pre=1;
                else
                   pre=ans[i/2-1]-pre;
                //printf("%d+++++++: ok\n",ans[i/2-1]-pre);
                ans[i/2]=pre*2;
            }
        }
        for(int i=0;i<=rowIndex/2;i++)
        {
            ans[rowIndex-i]=ans[i];
        }
        return ans;
        
        
    }
};