class Solution {
public:
   vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> com;
        combineRe(n, k, 1, com, res);
        return res;
    }
    
    void combineRe(int n, int k, int start, vector<int> &com, vector<vector<int> > &res){
        int m = com.size();
        if (m == k) {
            res.push_back(com);
            return;
        }
        for (int i = start; i <= n-(k-m)+1; ++i) {
            com.push_back(i);
            combineRe(n, k, i+1, com, res);
            com.pop_back();
        }
    }
};