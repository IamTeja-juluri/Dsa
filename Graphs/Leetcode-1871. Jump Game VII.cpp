class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {
        
        queue<int>q;
        q.push(0);
        
        int n=s.size();
        
        if(s[n-1]=='1')
            return false;
        
        int curr_max=0;
        
        while(!q.empty()){
            
            int qsize=q.size();
            
            for(int i=1;i<=qsize;i++){
                
                int idx=q.front();
                q.pop();
                
                 if(idx==n-1)
                    return true;
                
                for(int j=max(idx+minJump,curr_max);j<=min(idx+maxJump,n-1);j++){
                    if(s[j]=='0')
                    q.push(j);
                }
                //to avoid tle
                curr_max=max(curr_max,idx+maxJump+1);
            }            
        }

        return false;
    }
};
