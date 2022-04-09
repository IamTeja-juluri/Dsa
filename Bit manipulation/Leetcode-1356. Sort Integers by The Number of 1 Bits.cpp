class Solution {
public:
    
    int countsetbits(int num){
        
        int count=0;
        
        while(num){      
            count=count+(num&1);
            num=num>>1;
        }
        
        return count;
        
    }
    
    
    
    vector<int> sortByBits(vector<int>& arr) {
        
        multiset<pair<int,int> > st;
        
        for(auto x:arr){    
            int f=countsetbits(x);
            st.insert({f,x});
        }
        
        vector<int> ans;
        
        for(auto it:st){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
