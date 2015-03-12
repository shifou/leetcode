int read4(char *buf);
class Solution {
public:
    int read(char *buf, int n) {
        if(n<=0)
           return 0;
        char buffer[5]={0};
        int i,ct=n/4,hold,left = n%4;
        for(i=1;i<=ct;i++)
        {
            hold = read4(buffer);
            if(hold==0)
                break;
            memcpy(buf + (i-1)*4, buffer, hold);
            if(hold!=4)
                break;
        }
        if(i!=ct+1)
            return (i-1)*4+hold;
        if(left)
        {
            hold = read4(buffer);
            // left 1 read 3
            // left 2 read 1
            left = min(hold,left);
            if(left)
                memcpy(buf + ct*4, buffer, left);
            //buf[ct*4+left]=0;
            return ct*4+left;
        }
        else 
            return ct*4;
    }
};