class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        priority_queue<int, vector<int>, greater<int> >  h1;
        priority_queue<int, vector<int>, less<int> > h2;
        int num=(m+n)/2;
        if(num==0) num=1;
       
        for(int i=0;i<m;i++)
        {
            if(h1.size()<num) 
            {
                h1.push(A[i]);
            }
            else
            {
                int hold=h1.top();
            if(A[i]>h1.top())
            {
                //int hold=h1.top();
                h1.pop();
                h1.push(A[i]);
                h2.push(hold);
            }
            else h2.push(A[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
          if(h1.size()<num) 
            {
                h1.push(B[i]);
            }
            else
            {
                int hold=h1.top();
            if(B[i]>h1.top())
            {
                //int hold=h1.top();
                h1.pop();
                h1.push(B[i]);
                h2.push(hold);
            }
            else h2.push(B[i]);
            }
        }
        int a1,a2;
        if(h1.empty()&&!h2.empty())
          return h2.top();
         else if(h2.empty()&&!h1.empty())
          return h1.top();
        else
        {
            if((m+n)&1) return h2.top();
            else
            return (h1.top()*1.0+h2.top()*1.0)/2;
        }
    }
};