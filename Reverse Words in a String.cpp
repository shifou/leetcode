class Solution {
public:
    void reverseWords(string &s) {
        stack<string> ans;
        string hold;
        istringstream stream(s);
        while(stream>>hold)
			ans.push(hold);
	    int a=ans.size();
	    string ss="";
	    while(!ans.empty())
	    {
	        if(a!=ans.size())
	        ss+=" ";
	        string fk=ans.top();
	        ans.pop();
	       ss+=fk;
	    }
	    s=ss;
    }
};