class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size()==1) return 1;
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
            map<double,int> p;
            int same=0;
           // int yy=1;
           double f;
            int hold=1;
            for(int j=i+1;j<points.size();j++)
            {
                //if(i==j) continue;
                if(points[i].x==points[j].x&&points[i].y==points[j].y) same++;
                else
                {
                    if(points[i].x==points[j].x) f=999999999;
                    else
                    {
                        f= (points[j].y-points[i].y)*1.0/(points[j].x-points[i].x);
                    }
                    if(p.find(f)==p.end()) p[f]=2;
                        else
                            p[f]++;
                        if(p[f]>hold) hold=p[f];
                }
            }
            //hold=max(hold,yy);
            ans=max(ans,hold+same);
        }
        return ans;
    }
};