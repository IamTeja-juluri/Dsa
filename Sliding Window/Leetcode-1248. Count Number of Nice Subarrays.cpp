//java
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
     
      //idea is to treat odd numbers as 1 and even numbers as zeros 
        //den quesn transforms to finding no of subarrays with sum equal to k
        
        
        int n=nums.length;
        
        HashMap<Integer,Integer> hm=new HashMap<>();
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
                nums[i]=0;
            else
                nums[i]=1;
        }
        
        int pref_sum=0;
        int count=0;
        
        for(int i=0;i<n;i++){
            pref_sum+=nums[i];
            if(pref_sum==k)
                count+=1;
            if(hm.containsKey(pref_sum-k))
                count=count+hm.get(pref_sum-k);
            
            hm.put(pref_sum,hm.getOrDefault(pref_sum,0)+1);
        }
        
        return count;
    }
}
//c++
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
       
        for(int i=0;i<nums.size();i++){
            if((nums[i]%2)==0)
                nums[i]=0;
            else
                nums[i]=1;
        }
        
        unordered_map<int,int> mp;
        int pref_sum=0;
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            pref_sum+=nums[i];
            if(pref_sum==k)
                count+=1;
            if(mp.find(pref_sum-k)!=mp.end())
                count=count+mp[pref_sum-k];
            
            mp[pref_sum]+=1;
        }
        
        return count;
        
    }
};
