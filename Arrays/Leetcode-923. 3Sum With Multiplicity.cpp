//Soln using maps
class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
       
        unordered_map<int,int> mp;
        
        int count=0;
        int mod=1e9+7;
        
        for(int i=0;i<a.size();i++){
            
           count=(count+mp[target-a[i]])%mod;
           for(int j=0;j<i;j++)
               mp[a[i]+a[j]]++;
            
        }
       
        return count;
    }
};



//Soln using two ptrs

class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        
        long long count=0;
        int n=a.size();
        sort(a.begin(),a.end());
        int mod=1e9+7;
        
        for(int i=0;i<(n-2);i++){
            
            int targetsum=target-a[i];
            int p1=i+1;
            int p2=n-1;
            
            while(p1<p2){
                
                if((a[p1]+a[p2])<targetsum)
                    p1++;
                else if((a[p1]+a[p2])>targetsum)
                    p2--;
                
                else{
                    
                    long long l=1,r=1;
                    while(p1<p2 && a[p1]==a[p1+1]){
                        p1++;
                        l++;
                    }
                     while(p1<p2 && a[p2]==a[p2-1]){
                        p2--;
                        r++;
                    }
                    
                    if(p1==p2)
                        count=(count+(l*(l-1))/2)%mod;
                    else
                        count=(count+(l*r))%mod;
                    
                    p1++;
                    p2--;
                }
                
            }
            
        }
        
        return count;
        
        
    }
};
