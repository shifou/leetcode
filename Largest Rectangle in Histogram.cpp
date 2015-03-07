class Solution {
public:
    int largestRectangleArea(vector<int> &h) {
        int ans=0;
        int s=0,t=h.size()-1;
        stack<int> S;
        h.push_back(0);
        int sum = 0;  
       for (int i = 0; i < h.size(); i++) {  
            if (S.empty() || h[i] > h[S.top()]) S.push(i);  
            else {  
                 int tmp = S.top();  
                 S.pop();  
                 sum = max(sum, h[tmp]*(S.empty()? i : i-S.top()-1));  
                 i--;  
            }  
       }  
       return sum;  
    }
};