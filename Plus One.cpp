class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int carry=0;
        for(int i=digits.size()-1;i>=0;i--)
        {
             int hold= digits[i]+carry;
            if(i==digits.size()-1)
                hold+=1;
           
            digits[i]=hold%10;
            if(hold/10)
            {
                
                carry=hold/10;
            }
            else
            {
                carry=0;
            
                break;
            }
        }
        if(carry)
            digits.insert(digits.begin(),1);
        return digits;
    }
};