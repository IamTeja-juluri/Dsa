class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        if(start==goal)
            return 0;
        
        queue<int> q;
        q.push(start);
        int steps=0;
        unordered_map<int,int> visited;
        // visited[start]=true;
        
        while(!q.empty()){
            int n=q.size();
            for(int j=0;j<n;j++){
            int num=q.front();
            q.pop();
            if(num==goal)
                return steps;
            if(num<0 || num>1000 || visited[num]==1)
                continue;
            visited[num]=1;
            for(int i=0;i<nums.size();i++){
               q.push(num+nums[i]);
               q.push(num-nums[i]);
               q.push(num^nums[i]);
            }  
          }     
            steps+=1;
        }        
        
        return -1;
    }
};
