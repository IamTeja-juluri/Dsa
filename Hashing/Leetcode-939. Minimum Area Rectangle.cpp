class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
       set<pair<int,int> > st;
       
      for(auto x:points)
          st.insert({x[0],x[1]});
      
      int ans=INT_MAX;  
      
      for(int i=0;i<points.size();i++){
          
           int x1=points[i][0];
           int y1=points[i][1];
          
          for(int j=i+1;j<points.size();j++){
              
              int x2=points[j][0];
              int y2=points[j][1];
              
              if(st.find({x1,y2})!=st.end()  && st.find({x2,y1})!=st.end()){
                  int l=abs(x2-x1);
                  int r=abs(y2-y1);
                  if((l*r)!=0)
                      ans=min(ans,l*r);
              }
              
          }
      }
        
      if(ans==INT_MAX)
          ans=0;
        
      return ans;
        
    }
};
