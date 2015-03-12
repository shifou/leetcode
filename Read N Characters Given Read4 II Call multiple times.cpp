int read4(char *buf);
class Solution {
public:
    char buffer[5]={0};
    int last=0; // index 
    int size=0;
    int read(char *buf, int n) {
        if(n<=0)
           return 0;
        // last 1 size 3 n =1
        if(size-last>=n)
        {
            memcpy(buf , buffer+last, n);
            last+=n;
            return n;
        }
        // last 1 size 3 n =60
        memcpy(buf , buffer+last, size-last);
        n-=(size-last);
        last=size;
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
        {
            last=size=0;
            return (i-1)*4+hold;
        }
        if(left)
        {
            hold = read4(buffer);
            size=hold;
            // left 1 read 3
            // left 2 read 1
            left = min(hold,left);
            if(left)
                memcpy(buf + ct*4, buffer, left);
            //buf[ct*4+left]=0;
            last = left;
            return ct*4+left;
        }
        else 
        {
            last=size=0;
            return ct*4;
        }
    }
};