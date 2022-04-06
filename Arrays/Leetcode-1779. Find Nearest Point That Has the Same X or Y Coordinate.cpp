class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
     
        int idx=-1;
        int mindist=INT_MAX;
        int i=-1;
        for(auto p:points){
            int f=p[0];
            int s=p[1];
            ++i;
            if( (x==f) || (y==s) ){
                int currdist=abs(x-f)+abs(y-s);
                if(mindist>currdist){
                    mindist=currdist;
                    idx=i;
                }
            }
        }
        
        
        return idx;
    }
};
