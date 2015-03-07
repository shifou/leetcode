class Solution {
public:
    int atoi(string str) {
        if(str=="" || str.size()==0)
          return 0;
         int i=0;
         while(i<str.size() && str[i]==' ') i++;
         if(i==str.size())
            return 0;
        int neg=0;
        if(!isdigit(str[i]))
        {
            if(str[i]=='-') neg=1;
            else if(str[i]!='+')
              return 0;
            i++;
        }
        int ans=0;
         for(;i<str.size() && isdigit(str[i]);i++)
         {
             if(!neg && ans>INT_MAX/10) return INT_MAX;
             if(!neg && ans == INT_MAX/10 && (str[i]-'0')>=7) return INT_MAX;
             if(neg && -ans<INT_MIN/10)  return INT_MIN;
             if(neg && -ans==INT_MIN/10 && (str[i]-'0')>=8) return INT_MIN;
             ans=ans*10+str[i]-48;
         }
         if(neg)  return -ans;
         else return ans;
    }
};