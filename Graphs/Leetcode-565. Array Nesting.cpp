class Solution {
public:
    int ans;
    vector<bool> visited;
    void dfs(vector<int>&nums,int node,int c){
        
        if(visited[node]){
            ans=max(ans,c);
            return;
        }
        
        visited[node]=true;
        
        dfs(nums,nums[node],c+1);
        
        return;
    }
    
    
    
    int arrayNesting(vector<int>& nums) {
        
        ans=0;
        visited.resize(nums.size()+1,false);
        for(auto x:nums){
            if(!visited[x])
            dfs(nums,x,1);
        }
        
        return ans-1;
    }
};
