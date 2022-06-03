class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
     
        priority_queue<pair<int,int> > pq;
    
        for(int i=0;i<a.size();i++)
            pq.push({a[i]+b[i],i});
        
        int ascore=0,bscore=0;
        int mask=0;
        
        while(!pq.empty()){
            
            int val=pq.top().first;
            int idx=pq.top().second;
            
            pq.pop();
            
            if(mask==0)
                ascore+=a[idx];
            else
                bscore+=b[idx];
            
            mask=!mask;
        }
        
        if(ascore==bscore)
            return 0;
        
        if(ascore>bscore)
            return 1;
        
        return -1;
    }
};
