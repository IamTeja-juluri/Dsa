//java
class Solution {
    public List<Integer> findLonely(int[] nums) {
        
        List<Integer> l=new ArrayList<>();
        HashMap<Integer,Integer> hm=new HashMap<>(); 
        
        for(int x:nums){
            if(hm.containsKey(x))
                hm.put(x,hm.get(x)+1);
            else
                hm.put(x,1);
        }
        
        for(Map.Entry x:hm.entrySet()){
            
            int firstval=(int)x.getKey();
            
            int secondval=(int)x.getValue();
            
            if(secondval==1){
                if(hm.containsKey(firstval-1)==false && hm.containsKey(firstval+1)==false)
                    l.add(firstval);
            }
            
        }
        
        return l;
    }
}
//cpp
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        vector<int> res;
        
        unordered_map<int,int> mp;
        
        for(auto x:nums)
            mp[x]+=1;
            
        for(auto it:mp){
            if(it.second==1)
                if( (mp.find(it.first + 1)==mp.end() ) && (mp.find(it.first - 1)==mp.end() ) )
                    res.push_back(it.first);
        }    
        
        
        return res;
    }
};
