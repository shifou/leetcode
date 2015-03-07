class Solution {
public:
    string simplifyPath(string path) {
        if(path=="/../") return "/";
        string aa="";
        if(path=="/.") return "/";
        if(path=="/") return "/";
        for(int i=0;i<path.size();i++)
        {
            if(i==path.size()-1&&path[i]=='/') break;
            aa+=path[i];
            int tt=0;
            if(path[i]=='/')
            {
                for(int j=i+1;j<path.size();j++)
                 {
                   if(path[j]!='/')
                    break;
                  else 
                    tt++;
                 }
            }
            i+=tt;
        }
        stack<string> ans;
        for(int st=0,i=0;i<aa.size();)
        {
            i=aa.find('/',st+1);
            if(i==-1)
            {
                if(aa.substr(st+1)=="." )
                 break;
                 if(aa.substr(st+1)=="..")
                 {
                     if(!ans.empty())
                ans.pop();
                break;
                 }
                ans.push(aa.substr(st));
                break;
            }
            string hold=aa.substr(st,(i-st));
            st=i;
            i++;
            if(hold.substr(1)==".." ) 
            {
                if(!ans.empty())
                ans.pop();
            }
            else if(hold.substr(1)!=".")
            {
                ans.push(hold);
            }
        }
        string res="";
        while(!ans.empty())
        {
            string cc=ans.top();
            ans.pop();
            reverse(cc.begin(),cc.end());
            res+=cc;
        }
        reverse(res.begin(),res.end());
       if(res=="/.") return "/";
       if(res=="/..") return "/";
       if(res=="") return "/";
        return res;
        
    }
};