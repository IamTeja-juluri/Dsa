class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int ans=0;
        int n=fruits.size();
        int j=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[fruits[i]]+=1;
            while(mp.size()>2){
                mp[fruits[j]]-=1;
                if(mp[fruits[j]]==0)
                    mp.erase(fruits[j]);
                j+=1;
            }
            ans=max(ans,i-j+1);
        }
        
        
        return ans;
    }
};
