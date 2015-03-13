string range(int from, int to)
{
  if(from == to)
    return to_string(from);
  else
    return to_string(from)+ "->" to_string(to);
}
vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
  vector<string> res;
  if(n<=0)
  {
      res.push_back(range(lower,upper));
      return res;
  }
  int st = lower;
  if(st<A[0])
  {
      res.push_back(range(st,A[0]-1));
  }
  for (int i = 1; i < n; ++i) 
  {
      if(A[i]-A[i-1]<2)
         continue;
      else 
          res.push_back(range(A[i-1]+1,A[i]-1));
  }
  if(A[n-1]<upper)
  {
      res.push_back(range(A[n-1]+1,upper));
  }
  return res;
}