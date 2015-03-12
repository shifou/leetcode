class Solution {
public:
    void reverseWords(string &s) {
       reverse(s.begin(),s.end());
       for(int i=0;i<s.size();)
       {
       	   while(s[i]==' ') i++;
       	   int en = s.find(' ',i);
       	   if(en==-1) 
       	      en=s.size();
       	    reverse(s.begin()+i,s.begin()+en);
       	   i=en;
       }
    }
};