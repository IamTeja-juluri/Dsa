//java
class Solution {
    public int findMaxLength(int[] nums) {
        
        
        int pref=0;
        int ans=0;
        
        int n=nums.length;
        Map<Integer,Integer> mp=new HashMap<Integer,Integer>();
        mp.put(0,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                pref+=1;
            else
                pref-=1;
            if(mp.get(pref)!=null){
                ans=Math.max(ans,i-mp.get(pref));
                continue;
            }
            mp.put(pref,i);
        }
        return ans;
    }
}
//cpp

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        int ans=0;
        int pref=0;
        mp[0]=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                pref-=1;
            else
                pref+=1;
            if(mp.find(pref)!=mp.end()){
                ans=max(ans,i-mp[pref]);
                continue;
            }
            mp[pref]=i;
        }
        
        
        return ans;
        
    }
};
