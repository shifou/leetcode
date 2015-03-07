class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
        if(num.size()==0)
           return ans;
           sort(num.begin(),num.end());
   
         vector<int> fk;
            fk.push_back(num[0]);
        if(num.size()==1)
        {
           
            ans.push_back(fk);
            return ans;
        }
          
        queue< vector<int> > q;
        q.push(fk);
        int i=1;
        while(!q.empty())
        {
            vector<vector<int> > hold;
            while(!q.empty())
            {
                vector<int> tmp = q.front();
                q.pop();
                hold.push_back(tmp);
            }
            unordered_set<int> check;
            for(int j=0;j<hold.size();j++)
            {
                //11
                for(int k=0;k<=hold[j].size();)
                {
                    while(k&&k<=hold[j].size()&&hold[j][k-1]==num[i])
                    {
                        k++;
                    }
                    if(k>hold[j].size())
                      break;
                    vector<int> wait = hold[j];
                    wait.insert(wait.begin()+k,num[i]);
                    int fkk=0;
                    for(int p=0;p<wait.size();p++) fkk=fkk*10+wait[p];
                    if(check.find(fkk)==check.end())
                    {
                        q.push(wait);
                        check.insert(fkk);
                    }
                    k++;
                }
            }
            
            i++;
            if(i==num.size())
            {
                 while(!q.empty())
            {
                vector<int> tmp = q.front();
                q.pop();
                ans.push_back(tmp);
            }
              return ans;
            }
        }
    }
};