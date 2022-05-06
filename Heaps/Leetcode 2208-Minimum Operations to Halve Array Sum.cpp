class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        double s=0;
    
        priority_queue<double> pq;
        for(auto x:nums){
            s+=x;
            pq.push(x);
        }
        
        double s1=s/2;
       
        int cnt=0;
        
        while(!pq.empty()){
            
             cnt+=1;
            double x=pq.top();
            pq.pop();
            s=s-(x/2);
            if(s<=s1)
                break;
            pq.push(x/2);
           
        }
        
        
        return cnt;
    }
};
