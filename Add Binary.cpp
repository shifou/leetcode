class Solution {
public:
    string addBinary(string a, string b) {
    string ans="";
    int c=0;
    if(a.size()>b.size())
        swap(a,b);
    int h1=a.size()-1, h2=b.size()-1, pre=0;
    while(h1>=0 || h2>=0)
    {
        int hold;
        if(h1>=0)
        {
            hold = a[h1]-'0'+b[h2]-'0'+pre;
            pre = hold/2;
            b[h2]=hold%2 +'0';
            h1--;
        }
        else
        {
            hold = b[h2]-'0'+pre;
            pre = hold/2;
            b[h2]=hold%2 +'0';
            if(pre==0)
                break;
        }    
        h2--;
    }
    if(pre)
        b.insert(b.begin(),'1');
    return b;
}
};