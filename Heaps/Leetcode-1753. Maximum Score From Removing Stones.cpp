class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
       int ans=0;
        
       priority_queue<pair<int,char> > pq;
       
       pq.push({a,'a'});
       pq.push({b,'b'});
       pq.push({c,'c'});
       
       while(pq.size()>1){
           
           pair<int,char> p1=pq.top();
           pq.pop();
           
           pair<int,char> p2=pq.top();
           pq.pop();
           
           ans=ans+1;
           
           if(p1.first>1)
               pq.push({p1.first-1,p1.second}); 
           if(p2.first>1)
               pq.push({p2.first-1,p2.second});
       } 
        
       return ans; 
      
    }
};
