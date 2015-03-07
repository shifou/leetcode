class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
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
            for(int j=0;j<hold.size();j++)
            {
                
                for(int k=0;k<=hold[j].size();k++)
                {
                    vector<int> wait = hold[j];
                    wait.insert(wait.begin()+k,num[i]);
                    q.push(wait);
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
