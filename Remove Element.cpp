class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        vector<int> hold;
        for(int i=0;i<n;i++)
        {
            if(A[i]!=elem)
            hold.push_back(A[i]);
        }
        for(int i=0;i<hold.size();i++)
        {
            A[i]=hold[i];
        }
        
        return hold.size();
        
    }
};