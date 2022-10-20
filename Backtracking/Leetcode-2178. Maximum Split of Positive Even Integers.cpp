//Backtracking soln-TLE
class Solution {
public:
    
    set<long long>st;
    
    vector<long long> helper(long long curr_sum,long long finalSum){
        
        if(curr_sum==finalSum){
            vector<long long> ans;
            for(auto x:st)
                ans.push_back(x);
            return ans;
        }
        
        for(long long i=2;i<=finalSum;i+=2){
            if(st.find(i)!=st.end() or curr_sum+i>finalSum)
                continue;
            st.insert(i);
            vector<long long> res=helper(curr_sum+i,finalSum);
            if(res.size()>0)
                return res;
            st.erase(i);
        }
        
        return {};
    }
    
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        if(finalSum%2==1)
            return {};
        return helper(0,finalSum);  
        
        
    }
};
//GReedy soln-ac
vector<long long> maximumEvenSplit(long long finalSum) {
        
        if(finalSum%2==1)
            return {};
        
        vector<long long> ans;
        
        long long i=2,curr_sum=0;
        
        while(curr_sum+i<=finalSum){
            ans.push_back(i);
            curr_sum+=i;
            i+=2;
        }
        
        ans[ans.size()-1]+=finalSum-curr_sum;
        return ans;
        
    }
