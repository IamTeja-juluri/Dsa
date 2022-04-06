class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
      int n=score.size();
        
      vector<string> v(n,"");
        
      priority_queue<pair<int,int> > pq;
        
      for(int i=0;i<score.size();i++)
          pq.push({score[i],i});
        
      
      int k=1;
        
      while(!pq.empty()){
          
          int idx=pq.top().second;
          
          if(k==1)
              v[idx]="Gold Medal";
          
          else if(k==2)
              v[idx]="Silver Medal";
          
          else if(k==3)
              v[idx]="Bronze Medal";
          
          else
              v[idx]=to_string(k);
         
          k+=1;
         pq.pop();
          
      }
      
    
        return v;
    }
};
