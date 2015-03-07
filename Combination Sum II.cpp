class Solution {
public:
    void mlx(vector<vector<int> > &ans, vector<int> &num, vector<int> tmp, int pos, int pre, int hold,int &target)
    {
        if(hold==target)
        {
            ans.push_back(tmp);
        }
        for(int i=pos;i<num.size();i++)
        {
            if(i>pos&&num[i-1]==num[i])
              continue;
            if(num[i]>=pre && hold+num[i]<=target)
            {
                tmp.push_back(num[i]);
                mlx(ans,num,tmp,i+1,num[i],hold+num[i],target);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
     vector<vector<int> > ans;
     vector<int> tmp;
     mlx(ans,num,tmp,0,0,0,target);
     return ans;
    }
};