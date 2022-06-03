class Solution {
public:
    int racecar(int target) {
        
        
        queue<pair<long ,long> > q;
        
        q.push({0,1});
        long  cnt=0;
        
        set<pair<long,long> > st;
        st.insert({0,1});
        
        while(!q.empty()){
            
           int n=q.size();
            
           for(int i=1;i<=n;i++){
               
            long currpos=q.front().first;
            long currspeed=q.front().second;
            
            q.pop();
            
            if(currpos==target)
                return cnt;
               
            long nextPos1=currpos+currspeed;
            long nextspeed1=currspeed*2;
               
            if(st.find({nextPos1,nextspeed1})==st.end() and abs(target-nextPos1)<target){
                q.push({nextPos1,nextspeed1});
                st.insert({nextPos1,nextspeed1});
            }
                
            
            long nextPos2=currpos;
            
            long nextspeed2=currspeed>0?-1:1;
               
            if(st.find({nextPos2,nextspeed2})==st.end() and abs(target-nextPos2)<target){
                q.push({nextPos2,nextspeed2});
                st.insert({nextPos2,nextspeed2});
            }   
               
               
           }
            cnt+=1;   
        }
        
        return cnt;
        
    }
};
