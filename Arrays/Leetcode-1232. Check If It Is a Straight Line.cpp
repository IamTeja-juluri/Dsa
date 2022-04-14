class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
       int y1=0,x1=0;
        
       for(int i=1;i<coordinates.size();i++){
           
        int x=coordinates[i][0]-coordinates[i-1][0];
        int y=coordinates[i][1]-coordinates[i-1][1];
        
        if(i==1){
            y1=y;
            x1=x;
        }
        else{
            if( (y1*x)!=(y*x1) )
                return false;
        }
           x1=x;
           y1=y;
      
       }
        
        return true;
    }
};
