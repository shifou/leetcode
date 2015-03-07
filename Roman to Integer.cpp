class Solution {
public:
    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<char, int> hash;
        hash['M']=1000;
        hash['D']=500;
        hash['L']=50;
        hash['V']=5;
        hash['C']=100;
        hash['X']=10;
        hash['I']=1;
        int hold = 0;
        int sum = 0;
        for(int i=0;i<s.size();i++)
        {
            if(hash.find(s[i])!=hash.end())
            {
                int temp=hash[s[i]];
                if(temp>hold)
                {
                    sum += temp-2*hold;
                    
                }
                else 
                    sum+=temp;
                hold =temp;
            }
        }
        return sum;
    }
};