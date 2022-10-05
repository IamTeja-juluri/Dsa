class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        int n=hand.size();
        
        for(auto x:hand)
            mp[x]+=1;
        
        int no_of_groups=n/groupSize;
        
        int groups=0;
        
        while(mp.size()!=0 ){
            
            auto it=mp.begin();
            int num=it->first;
            int size=0;
            
             while(mp.find(num)!=mp.end() and size<groupSize){
                mp[num]-=1;
                if(mp[num]==0)
                    mp.erase(num);
                num+=1;
                size+=1;
            }
            
            if(size==groupSize)
                groups+=1;
            else
                return false;
        }
        
        
        return groups==no_of_groups;
    }
};
