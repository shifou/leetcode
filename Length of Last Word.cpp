class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str(s);
        istringstream in(str);
        string hold="";
        while(in>>hold)
        {
            
        }
        return hold.size();
    }
};