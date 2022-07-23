class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int,int>mp;
        
        int ans=INT_MAX;
        int j=0;
        
        for(int i=0;i<cards.size();i++){
           mp[cards[i]]+=1;
           if(mp[cards[i]]==2){
               while(cards[j]!=cards[i]){
                   mp[cards[j]]-=1;
                   j+=1;
               }
               ans=min(ans,i-j+1);
               mp[cards[j]]-=1;
               j+=1;
           } 
          
        }
        
        return ans==INT_MAX?-1:ans;
    }
};
