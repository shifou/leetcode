bool isprime[2250001];
class Solution {
public:
 vector<int> primes;
Solution ()
{
   
        memset(isprime,1,sizeof(isprime));
        int up =  1500;
        int ct=0;
        primes.resize(166152);
        primes[ct++]=2;
        primes[ct++]=3;
        primes[ct++]=5;
        for(int i=7;i<up;i+=2)
        {
            if(i%2==0 || i%3==0 || i%5==0){
                isprime[i]=0;
                continue;
            } 
            if(isprime[i])
            {
                primes[ct++]=i;
                for(int j=i*i;j<2250001;j+=i)
                    isprime[j]=0;
            }
        }
        for(int i=1501;i<2250001;i+=2)
        {
            if(i%3==0 || i%5==0 || i%7==0 || i%11==0) continue;
            if(isprime[i])
            {
                 primes[ct++]=i;
            }
        }
}
      int countPrimes(int n) {
        if(n<2)
            return 0;
        int l=0,r=primes.size(),ans=-1;

         while(l<r)
        {

            int mid = (l+r)/2;
                    
            if(n>primes[mid])
                l=mid+1;
            else
                r=mid;
        }
        return l;
        
    }
};