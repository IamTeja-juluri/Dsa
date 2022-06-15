class Solution {
public:
    struct compare{
     bool operator()(string s1,string s2){
        
        if(s1.length()==s2.length())
            return s1>s2;
        
        return s1.length()>s2.length();
        
    }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
     
        priority_queue<string,vector<string>,compare > pq;
       
        for(auto x:nums){
            pq.push(x);
            if(pq.size()>k)
                pq.pop();
        }
       
        
        return pq.top();
    }
};
